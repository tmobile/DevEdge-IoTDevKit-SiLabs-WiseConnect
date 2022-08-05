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
/**
 * @file    rsi_wlan_config.h
 * @version 0.1
 * @date    01 Feb 2021
 *
 *
 *
 *  @brief : This file contains user configurable details to configure the device
 *
 *  @section Description  This file contains user configurable details to configure the device
 */

#ifndef RSI_WLAN_CONFIG_H_
#define RSI_WLAN_CONFIG_H_
/*=======================================================================*/
//  ! INCLUDES
/*=======================================================================*/
#include <rsi_bt.h>
/***********************************************************************************************************************************************/
//! WLAN SAPI CONFIG DEFINES
/***********************************************************************************************************************************************/
//! WLAN Mode
#define RSI_WLAN_MODE RSI_WLAN_CLIENT_MODE
//! CO-EX Mode configuration
#define RSI_COEX_MODE 5
#define ENABLE_1P8V   1 //! Disable this when using 3.3v
//! Enable feature
#define RSI_ENABLE 1
//! Disable feature
#define RSI_DISABLE 0
//! To enable concurrent mode
#define CONCURRENT_MODE RSI_DISABLE

//! BT power control
#define BT_PWR_CTRL_DISABLE 0
#define BT_PWR_CTRL         1
#define BT_PWR_INX          10

/*=======================================================================*/
//! Opermode command parameters
/*=======================================================================*/
#define RSI_FEATURE_BIT_MAP (FEAT_SECURITY_OPEN) //! To set wlan feature select bit map

#define RSI_TCP_IP_BYPASS RSI_DISABLE //! TCP IP BYPASS feature check

#define RSI_TCP_IP_FEATURE_BIT_MAP \
  (TCP_IP_FEAT_DHCPV4_CLIENT) //! TCP/IP feature select bitmap for selecting TCP/IP features

#define RSI_EXT_TCPIP_FEATURE_BITMAP 0

#define RSI_CUSTOM_FEATURE_BIT_MAP FEAT_CUSTOM_FEAT_EXTENTION_VALID

/*=======================================================================*/
//! To set Extended custom feature select bit map
/*=======================================================================*/
#if ENABLE_1P8V
#define RSI_EXT_CUSTOM_FEATURE_BIT_MAP (EXT_FEAT_384K_MODE | EXT_FEAT_1P8V_SUPPORT)
#else
#define RSI_EXT_CUSTOM_FEATURE_BIT_MAP (EXT_FEAT_384K_MODE)
#endif

#define RSI_BT_FEATURE_BITMAP (A2DP_PROFILE_ENABLE | A2DP_SOURCE_ROLE_ENABLE | BT_RF_TYPE)
/*=======================================================================*/
//! Band command parameters
/*=======================================================================*/
#define RSI_BAND RSI_BAND_2P4GHZ //! RSI_BAND_5GHZ or RSI_BAND_2P4GHZ

//! including the common defines
#include "rsi_wlan_common_config.h"
#endif
