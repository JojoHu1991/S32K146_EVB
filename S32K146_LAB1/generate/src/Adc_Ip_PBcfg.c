/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K1_RTD_3_0_0_QLP06_D2603_ASR_REL_4_7_REV_0000_20260320
*
*   Copyright 2020-2026 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup adc_ip_config Adc IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc_Ip_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID_PBCFG_C                     43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C      4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C      7
#define ADC_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C   0
#define ADC_IP_SW_MAJOR_VERSION_PBCFG_C              3
#define ADC_IP_SW_MINOR_VERSION_PBCFG_C              0
#define ADC_IP_SW_PATCH_VERSION_PBCFG_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Ip_PBcfg.c file and Adc_Ip_PBcfg.h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_PBCFG_C != ADC_IP_VENDOR_ID_PBCFG)
    #error "Adc_Ip_PBcfg.c and Adc_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if Adc_Ip_PBcfg.c file and Adc_Ip_PBcfg.h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ADC_IP_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_PBCFG_C != ADC_IP_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_PBCFG_C != ADC_IP_AR_RELEASE_REVISION_VERSION_PBCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Ip_PBcfg.c and Adc_Ip_PBcfg.h are different"
#endif

/* Check if Adc_Ip_PBcfg.c file and Adc_Ip_PBcfg.h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_PBCFG_C != ADC_IP_SW_MAJOR_VERSION_PBCFG) || \
     (ADC_IP_SW_MINOR_VERSION_PBCFG_C != ADC_IP_SW_MINOR_VERSION_PBCFG) || \
     (ADC_IP_SW_PATCH_VERSION_PBCFG_C != ADC_IP_SW_PATCH_VERSION_PBCFG) \
    )
  #error "Software Version Numbers of Adc_Ip_PBcfg.c and Adc_Ip_PBcfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

static const Adc_Ip_ChanConfigType AdcIpChansConfig_0[1U] =
{
    {
        0U, /* ChnIdx */
        ADC_IP_INPUTCHAN_EXT12, /* Channel */
    #if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
        (boolean)FALSE /* InterruptEnable */
    #endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
    }
};


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/**
* @brief          ADC Ip Config for the ADC0 configuration variant .
*/
const Adc_Ip_ConfigType AdcHwUnit_0 =
{
    ADC_IP_CLK_FULL_BUS, /* ClockDivide */
    ADC_IP_CLK_EIGHTH_BUS, /* CalibrationClockDivide */
    ADC_IP_CLK_ALT_1, /* InputClock */
    1U, /* SampleTime */
    (boolean)FALSE, /* AvgEn */
    ADC_IP_AVG_4_CONV, /* AvgSel */
    ADC_IP_RESOLUTION_12BIT, /* Resolution */
    ADC_IP_TRIGGER_SOFTWARE, /* TriggerMode */
#if (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON)
    ADC_IP_PRETRIGGER_SEL_PDB, /* PretriggerSel */
    ADC_IP_TRIGGER_SEL_PDB, /* TriggerSel */
#endif /* (ADC_IP_ENABLE_SIM_SOURCE_SELECTION == STD_ON) */
    (boolean)FALSE, /* DmaEnable */
    ADC_IP_VOLTAGEREF_VREF, /* VoltageRef */
    (boolean)FALSE, /* ContinuousConvEnable */
#if (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON)
    (boolean)FALSE, /* SupplyMonitoringEnable */
#endif /* (ADC_IP_SUPPLY_MONITORING_ENABLED == STD_ON) */
    (boolean)FALSE, /* CompareEnable */
    (boolean)FALSE, /* CompareGreaterThanEnable */
    (boolean)FALSE, /* CompareRangeFuncEnable */
    0U, /* CompVal1 */
    0U, /* CompVal2 */
    4U, /* UsrGain */
    0U, /* UsrOffset */
    1U, /* NumChannels */
    AdcIpChansConfig_0, /* ChannelConfigs */
#if (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON)
    &adc_Potentiometer_Complete_Notification /* ConversionCompleteNotification */
#endif /* (ADC_IP_AIEN_INTERRUPT_ENABLE == STD_ON) */
};


#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

