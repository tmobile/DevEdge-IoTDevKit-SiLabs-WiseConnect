/*******************************************************************************
* @file  rsi_wlan_config.h
* @brief 
*******************************************************************************
* # License
* Copyright 2021 Silicon Laboratories Inc. http://www.silabs.com/
*******************************************************************************
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*  http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
******************************************************************************/

#ifndef RSI_CONFIG_H
#define RSI_CONFIG_H

#include "rsi_wlan_defines.h"
/***********************************************************************************************************************************************/
//! WLAN SAPI CONFIG DEFINES
/***********************************************************************************************************************************************/
//! Enable feature
#define RSI_ENABLE 1
//! Disable feature
#define RSI_DISABLE 0
//! To enable concurrent mode
#define CONCURRENT_MODE RSI_DISABLE

/*=======================================================================*/
//! Opermode command parameters
/*=======================================================================*/

#define RSI_FEATURE_BIT_MAP \
  (FEAT_ULP_GPIO_BASED_HANDSHAKE | FEAT_DEV_TO_HOST_ULP_GPIO_1) //! To set wlan feature select bit map
#define RSI_TCP_IP_BYPASS RSI_DISABLE                           //! TCP IP BYPASS feature check
#define RSI_TCP_IP_FEATURE_BIT_MAP \
  (TCP_IP_FEAT_DHCPV4_CLIENT) //! TCP/IP feature select bitmap for selecting TCP/IP features
#define RSI_EXT_TCPIP_FEATURE_BITMAP 0

#define RSI_CUSTOM_FEATURE_BIT_MAP FEAT_CUSTOM_FEAT_EXTENTION_VALID //! To set custom feature select bit map

#define RSI_EXT_CUSTOM_FEATURE_BIT_MAP (EXT_FEAT_LOW_POWER_MODE | EXT_FEAT_XTAL_CLK_ENABLE | EXT_FEAT_384K_MODE)

#define RSI_BT_FEATURE_BITMAP (BT_RF_TYPE)
/*=======================================================================*/
//! Band command parameters
/*=======================================================================*/
//! RSI_BAND_2P4GHZ(2.4GHz) or RSI_BAND_5GHZ(5GHz) or RSI_DUAL_BAND
#define RSI_BAND RSI_BAND_2P4GHZ //! RSI_BAND_5GHZ or RSI_BAND_2P4GHZ

/*=======================================================================*/
//! Power save command parameters
/*=======================================================================*/
//! set handshake type of power mode
#define RSI_HAND_SHAKE_TYPE GPIO_BASED

//! 0 - LP, 1- ULP mode with RAM retention and 2 - ULP with Non RAM retention
#define RSI_SELECT_LP_OR_ULP_MODE RSI_ULP_WITH_RAM_RET

//! set DTIM aligment required
//! 0 - module wakes up at beacon which is just before or equal to listen_interval
//! 1 - module wakes up at DTIM beacon which is just before or equal to listen_interval
#define RSI_DTIM_ALIGNED_TYPE 0

//! Monitor interval for the FAST PSP mode
//! default is 50 ms, and this parameter is valid for FAST PSP only
#define RSI_MONITOR_INTERVAL 50
/***********************************************************************************************************************************************/

//! Number of DTIMs to skip during powersave
#define RSI_NUM_OF_DTIM_SKIP 0

#define TCP_RX_WINDOW_DIV_FACTOR 44
//! including the common defines
#include "rsi_wlan_common_config.h"

#endif
