/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : S32K14X
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K1_RTD_3_0_0_QLP06_D2603_ASR_REL_4_7_REV_0000_20260320
*
* Copyright 2020-2026 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

/* Including necessary configuration files. */
#include "Mcal.h"
#include "Clock_Ip.h"
#include "Port_Ci_Port_Ip.h"

volatile int exit_code = 0;
/* User includes */

/* 红灯控制 - PTD15, 输出高亮/低灭 */
#define RED_LED_PIN       (15U)
#define RED_LED_ON()      (IP_PTD->PSOR = (1U << RED_LED_PIN))   /* 输出高 -> 红灯亮 */
#define RED_LED_OFF()     (IP_PTD->PCOR = (1U << RED_LED_PIN))   /* 输出低 -> 红灯灭 */
#define RED_LED_TOGGLE()  (IP_PTD->PTOR = (1U << RED_LED_PIN))  /* 翻转输出 */

/* 绿灯控制 - PTD16, 输出高亮/低灭 */
#define GREEN_LED_PIN       (16U)
#define GREEN_LED_ON()      (IP_PTD->PSOR = (1U << GREEN_LED_PIN))   /* 输出高 -> 绿灯亮 */
#define GREEN_LED_OFF()     (IP_PTD->PCOR = (1U << GREEN_LED_PIN))   /* 输出低 -> 绿灯灭 */
#define GREEN_LED_TOGGLE()  (IP_PTD->PTOR = (1U << GREEN_LED_PIN))  /* 翻转输出 */

/* 蓝灯控制 - PTD0, 输出高亮/低灭 */
#define BLUE_LED_PIN       (0U)
#define BLUE_LED_ON()      (IP_PTD->PSOR = (1U << BLUE_LED_PIN))   /* 输出高 -> 蓝灯亮 */
#define BLUE_LED_OFF()     (IP_PTD->PCOR = (1U << BLUE_LED_PIN))   /* 输出低 -> 蓝灯灭 */
#define BLUE_LED_TOGGLE()  (IP_PTD->PTOR = (1U << BLUE_LED_PIN))  /* 翻转输出 */

/* 按键读取 - PTC12(SW2) / PTC13(SW3), 按下为高电平(active-high, 内部下拉) */
#define SW2_PRESSED()      ((IP_PTC->PDIR & (1U << 12)) != 0U)
#define SW3_PRESSED()      ((IP_PTC->PDIR & (1U << 13)) != 0U)

/* 软件延时 - 基于48MHz主频, 约1ms (可根据实际主频调整) */
static void delay_ms(uint32 ms)
{
    volatile uint32 i, j;
    for (i = 0U; i < ms; i++)
    {
        for (j = 0U; j < 8000U; j++)
        {
            __asm volatile("nop");
        }
    }
}

/* 按键检测 - 非阻塞, 配合主循环10ms tick */
/* 按下累计 5 tick (50ms) 触发一次, 松开后才能再次触发 */
#define KEY_DEBOUNCE_TICKS    (5U)

/* 按键状态 */
typedef struct {
    uint8 cnt;   /* 按下累计tick数 */
    uint8 trg;   /* 是否已触发过(锁定) */
} KeyState_t;

/*!
 * \brief 扫描一次按键状态
 * \param ks      按键状态指针
 * \param pressed 当前是否按下 (1=按下, 0=松开)
 * \return 1=本次触发翻转, 0=无触发
 */
static uint8 key_scan(KeyState_t *ks, uint8 pressed)
{
    uint8 fire = 0U;
    if (pressed)
    {
        if (!ks->trg)
        {
            ks->cnt++;
            if (ks->cnt >= KEY_DEBOUNCE_TICKS)
            {
                fire = 1U;
                ks->trg = 1U;   /* 触发后锁定, 等松开 */
                ks->cnt = 0U;
            }
        }
    }
    else
    {
        /* 松开 -> 清零, 准备下一次 */
        ks->cnt = 0U;
        ks->trg = 0U;
    }
    return fire;
}

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    /* Write your code here */

    /* 初始化时钟 - 必须在访问外设寄存器之前调用, 否则触发 HardFault */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

    /* 初始化引脚  */
    Port_Ci_Port_Ip_Init(NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
                         g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

    uint32 blue_toggle_cnt = 0U;  /* 蓝灯翻转计时 (ms) */
    uint8  blue_auto = 1U;        /* 蓝灯自动翻转使能 */
    KeyState_t sw2_key = {0};     /* SW2 按键状态 */
    KeyState_t sw3_key = {0};     /* SW3 按键状态 */

    for(;;)
    {
        /* 10ms 循环周期, 兼顾蓝灯计时和按键扫描 */
        delay_ms(10U);
        blue_toggle_cnt += 10U;

        /* SW2 按下50ms触发 -> 切换绿灯 + 关闭蓝灯 */
        if (key_scan(&sw2_key, SW2_PRESSED() ? 1U : 0U))
        {
            GREEN_LED_TOGGLE();
            BLUE_LED_OFF();
            blue_auto = 0U;
        }

        /* SW3 按下50ms触发 -> 切换红灯 + 关闭蓝灯 */
        if (key_scan(&sw3_key, SW3_PRESSED() ? 1U : 0U))
        {
            RED_LED_TOGGLE();
            BLUE_LED_OFF();
            blue_auto = 0U;
        }

        /* 蓝灯 1Hz 自动翻转 (500ms 亮 + 500ms 灭) */
        if (blue_auto && blue_toggle_cnt >= 500U)
        {
            BLUE_LED_TOGGLE();
            blue_toggle_cnt = 0U;
        }

        if(exit_code != 0)
        {
            break;
        }
    }
    return exit_code;
}

/** @} */
