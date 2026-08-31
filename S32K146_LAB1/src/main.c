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

    /* 以0.5Hz闪烁: 周期2000ms = 1000ms亮 + 1000ms灭, 每1000ms翻转一次 */
    for(;;)
    {
        RED_LED_TOGGLE();
        delay_ms(1000U);
        RED_LED_TOGGLE();
        GREEN_LED_TOGGLE();
        delay_ms(1000U);
        GREEN_LED_TOGGLE();
        BLUE_LED_TOGGLE();
        delay_ms(1000U);
        BLUE_LED_TOGGLE();
        delay_ms(1000U);
        if(exit_code != 0)
        {
            break;
        }
    }
    return exit_code;
}

/** @} */
