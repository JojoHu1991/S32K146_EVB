/*==================================================================================================
* Dr_Adc.c - ADC 驱动模块
* 电位计: PTC14 -> ADC0_SE12, 12bit, 软件触发轮询模式
* 打印输出: 经 LPUART1 (PTC6/PTC7, OpenSDA 虚拟串口)
==================================================================================================*/
#include "Dr_Adc.h"
#include "Adc_Ip.h"
#include "Adc_Ip_PBcfg.h"
#include "Lpuart_Uart_Ip.h"

#define ADC_INST           (0U)
#define POT_CHANNEL        ADC_IP_INPUTCHAN_EXT12
#define ADC_UART_INST      LPUART_UART_IP_INSTANCE_USING_1
#define ADC_UART_TIMEOUT   (100000U)   /* 发送超时 us */

/*==================================================================================================
*                              PRIVATE FUNCTIONS
==================================================================================================*/

/* UART 发送字符串 */
static void adc_uart_puts(const char *s)
{
    uint32 len = 0U;
    while (s[len] != '\0')
    {
        len++;
    }
    (void)Lpuart_Uart_Ip_SyncSend(ADC_UART_INST, (const uint8 *)s, len, ADC_UART_TIMEOUT);
}

/* 无符号数转 ASCII (返回长度, 不含结尾0) */
static uint8 adc_u16_to_str(uint16 v, char *dst)
{
    char tmp[5];
    uint8 n = 0U, i;

    if (v == 0U)
    {
        dst[0] = '0';
        dst[1] = '\0';
        return 1U;
    }
    while (v > 0U)
    {
        tmp[n++] = (char)('0' + (v % 10U));
        v /= 10U;
    }
    for (i = 0U; i < n; i++)
    {
        dst[i] = tmp[n - 1U - i];
    }
    dst[n] = '\0';
    return n;
}

/*==================================================================================================
*                              PUBLIC FUNCTIONS
==================================================================================================*/

void Dr_Adc_Init(void)
{
    Adc_Ip_Init(ADC_INST, &AdcHwUnit_0);
}

uint16 Dr_Adc_ReadPotentiometer(void)
{
    Adc_Ip_StartConversion(ADC_INST, POT_CHANNEL, FALSE);
    while (!Adc_Ip_GetConvCompleteFlag(ADC_INST, 0U))
    {
        /* 等待转换完成, 12bit单次转换仅需数us */
    }
    return Adc_Ip_GetConvData(ADC_INST, 0U);
}

/* 打印电位计采样值: raw(0~4095) + 换算电压(mV, 假设VREFH=3.3V) */
void Dr_Adc_PrintPotentiometer(uint16 raw)
{
    char buf[32];
    uint8 pos = 0U;
    uint32 mv = ((uint32)raw * 3300U) / 4095U;

    buf[pos]='P'; buf[pos+1]='O'; buf[pos+2]='T'; buf[pos+3]=' ';
    pos += 4U;
    (void)adc_u16_to_str(raw, &buf[pos]);
    while (buf[pos] != '\0') { pos++; }
    buf[pos++]=' '; buf[pos++]='m'; buf[pos++]='v'; buf[pos++]='=';
    (void)adc_u16_to_str((uint16)mv, &buf[pos]);
    while (buf[pos] != '\0') { pos++; }
    buf[pos++]='\r'; buf[pos++]='\n'; buf[pos]='\0';

    adc_uart_puts(buf);
}

/*==================================================================================================
* ADC0 通道转换完成通知 (中断上下文, 需保持短小)
*
* 注意: 当前通道配置 InterruptEnable=FALSE (轮询模式), 此回调不会被触发;
* 但生成的 AdcHwUnit_0 配置引用了本函数地址, 必须提供定义否则链接报错。
* 若以后要启用中断模式, 需要:
*   1. 在 .mex 中把 ADC 通道 InterruptEnable 打开并重新生成
*   2. Vector_Table.s 为硬编码 undefined_handler (无弱符号机制),
*      需把 ADC0 对应向量行改为 ADC0_IRQHandler, 并在其中调用 Adc_Ip_IRQHandler(0U)
*   3. 使能 NVIC 中 ADC0 中断
==================================================================================================*/
void adc_Potentiometer_Complete_Notification(const uint8 ControlChanIdx)
{
    (void)ControlChanIdx;
}
