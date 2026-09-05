#ifndef DR_ADC_H
#define DR_ADC_H
/*==================================================================================================
* Dr_Adc.h - ADC 驱动模块
* 电位计: PTC14 -> ADC0_SE12, 12bit, 软件触发轮询模式
* 打印输出: 经 LPUART1 (PTC6/PTC7, OpenSDA 虚拟串口)
==================================================================================================*/
#include "Std_Types.h"   /* uint16 */

/* 初始化 ADC0 (使用生成的 AdcHwUnit_0 配置) */
void Dr_Adc_Init(void);

/* 读取电位计原始值 0~4095 (阻塞等待单次转换完成, 仅需数us) */
uint16 Dr_Adc_ReadPotentiometer(void);

/* 打印电位计采样值: "POT raw=xxxx mv=xxxx" */
void Dr_Adc_PrintPotentiometer(uint16 raw);

#endif /* DR_ADC_H */
