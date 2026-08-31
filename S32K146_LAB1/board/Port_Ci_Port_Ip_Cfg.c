/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7 
*   Platform             : CORTEXM
*   Peripheral           : PORT_CI
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K1_S32M24_RTD_3_0_0_QLP06_D2603_ASR_REL_4_7_REV_0000_20260320
*
*   Copyright 2020-2026 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v17.0
processor: S32K146
package_id: S32K146_LQFP144
mcu_data: PlatformSDK_S32K1_S32M24
processor_version: 0.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */
/*==================================================================================================*/

/**
*   @file      Port_Ci_Port_Ip_Cfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Port_Ci_Port_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PORT_CI_PORT_IP_VENDOR_ID_CFG_C                       43
#define PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_C        7
#define PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define PORT_CI_PORT_IP_SW_MAJOR_VERSION_CFG_C                3
#define PORT_CI_PORT_IP_SW_MINOR_VERSION_CFG_C                0
#define PORT_CI_PORT_IP_SW_PATCH_VERSION_CFG_C                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Port_Ci_Port_Ip_Cfg.c and Port_Ci_Port_Ip_Cfg.h are of the same vendor */
#if (PORT_CI_PORT_IP_VENDOR_ID_CFG_C != PORT_CI_PORT_IP_VENDOR_ID_CFG_H)
    #error "Port_Ci_Port_Ip_Cfg.c and Port_Ci_Port_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Port_Ci_Port_Ip_Cfg.c and Port_Ci_Port_Ip_Cfg.h are of the same Autosar version */
#if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_C    != PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_C    != PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Port_Ci_Port_Ip_Cfg.c and Port_Ci_Port_Ip_Cfg.h are different"
#endif
/* Check if Port_Ci_Port_Ip_Cfg.c and Port_Ci_Port_Ip_Cfg.h are of the same Software version */
#if ((PORT_CI_PORT_IP_SW_MAJOR_VERSION_CFG_C != PORT_CI_PORT_IP_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_CI_PORT_IP_SW_MINOR_VERSION_CFG_C != PORT_CI_PORT_IP_SW_MINOR_VERSION_CFG_H) || \
     (PORT_CI_PORT_IP_SW_PATCH_VERSION_CFG_C != PORT_CI_PORT_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Port_Ci_Port_Ip_Cfg.c and Port_Ci_Port_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                             LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                             LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                            LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                           LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                           GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                           GLOBAL VARIABLES
==================================================================================================*/


/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
PortContainer_0_BOARD_InitPeripherals:
- options: {callFromInitBoot: 'true', coreID: core0}
- pin_list:
  - {pin_num: '70', peripheral: PORTC, signal: 'port, 13', pin_signal: PTC13, direction: INPUT, PE: state_1, PS: state_0}
  - {pin_num: '71', peripheral: PORTC, signal: 'port, 12', pin_signal: PTC12, direction: INPUT, PE: state_1, PS: state_0}
  - {pin_num: '4', peripheral: PORTD, signal: 'port, 0', pin_signal: PTD0, direction: OUTPUT, initValue: state_0}
  - {pin_num: '28', peripheral: PORTD, signal: 'port, 16', pin_signal: PTD16, direction: OUTPUT, initValue: state_0}
  - {pin_num: '29', peripheral: PORTD, signal: 'port, 15', pin_signal: PTD15, direction: OUTPUT, initValue: state_0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/* Generate array of configured pin structures */
Port_Ci_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals[NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals] = {
    {
        .portBase        = IP_PORTC,
        .gpioBase        = IP_PTC,
        .pinPortIdx      = 12U,
        .pullConfig      = PORT_INTERNAL_PULL_DOWN_ENABLED,
        .driveStrength   = PORT_DRIVE_STRENGTH_LOW,
        .passiveFilter   = (boolean)FALSE,
        .mux             = PORT_MUX_AS_GPIO,
        .lockRegister    = PORT_LOCK_REGISTER_DISABLED,
        .direction       = PORT_CI_PORT_PIN_IN,
        .digitalFilter   = (boolean)FALSE,
        .initValue       = 0U,
    },
    {
        .portBase        = IP_PORTC,
        .gpioBase        = IP_PTC,
        .pinPortIdx      = 13U,
        .pullConfig      = PORT_INTERNAL_PULL_DOWN_ENABLED,
        .driveStrength   = PORT_DRIVE_STRENGTH_LOW,
        .passiveFilter   = (boolean)FALSE,
        .mux             = PORT_MUX_AS_GPIO,
        .lockRegister    = PORT_LOCK_REGISTER_DISABLED,
        .direction       = PORT_CI_PORT_PIN_IN,
        .digitalFilter   = (boolean)FALSE,
        .initValue       = 0U,
    },
    {
        .portBase        = IP_PORTD,
        .gpioBase        = IP_PTD,
        .pinPortIdx      = 0U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength   = PORT_DRIVE_STRENGTH_LOW,
        .passiveFilter   = (boolean)FALSE,
        .mux             = PORT_MUX_AS_GPIO,
        .lockRegister    = PORT_LOCK_REGISTER_DISABLED,
        .direction       = PORT_CI_PORT_PIN_OUT,
        .digitalFilter   = (boolean)FALSE,
        .initValue       = 0U,
    },
    {
        .portBase        = IP_PORTD,
        .gpioBase        = IP_PTD,
        .pinPortIdx      = 15U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength   = PORT_DRIVE_STRENGTH_LOW,
        .passiveFilter   = (boolean)FALSE,
        .mux             = PORT_MUX_AS_GPIO,
        .lockRegister    = PORT_LOCK_REGISTER_DISABLED,
        .direction       = PORT_CI_PORT_PIN_OUT,
        .digitalFilter   = (boolean)FALSE,
        .initValue       = 0U,
    },
    {
        .portBase        = IP_PORTD,
        .gpioBase        = IP_PTD,
        .pinPortIdx      = 16U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveStrength   = PORT_DRIVE_STRENGTH_LOW,
        .passiveFilter   = (boolean)FALSE,
        .mux             = PORT_MUX_AS_GPIO,
        .lockRegister    = PORT_LOCK_REGISTER_DISABLED,
        .direction       = PORT_CI_PORT_PIN_OUT,
        .digitalFilter   = (boolean)FALSE,
        .initValue       = 0U,
    },
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*==================================================================================================
                                      LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                           LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                           GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
