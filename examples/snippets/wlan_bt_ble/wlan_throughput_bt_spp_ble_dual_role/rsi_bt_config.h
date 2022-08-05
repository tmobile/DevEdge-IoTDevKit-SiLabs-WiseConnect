/*******************************************************************************
* @file  rsi_bt_config.h
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
 * @file     rsi_bt_config.h
 * @version  0.1  
 * @date     01 Feb 2021
 *
 *
 *
 *  @brief : This file contain definitions and declarations of BT APIs.
 *
 *  @section Description  This file contains definitions and declarations required to
 *  configure BT module.
 *
 *
 */

#ifndef RSI_BT_CONFIG_H
#define RSI_BT_CONFIG_H

#include "rsi_bt_common.h"
#include <rsi_data_types.h>
#include "rsi_common_config.h"

/***********************************************************************************************************************************************/
//! BT_SPP APP CONFIG defines
/***********************************************************************************************************************************************/
#define RSI_BT_REMOTE_BD_ADDR (void *)"EA:D1:01:01:82:4C"
#define SPP_SLAVE             0
#define SPP_MASTER            1
#define SPP_MODE              SPP_SLAVE //! type of Module mode
#if (SPP_MODE == SPP_MASTER)
#define RSI_BT_LOCAL_NAME (void *)"SPP_MASTER"
#define INQUIRY_ENABLE    0 //! To scan for device and connect
#if INQUIRY_ENABLE
#define MAX_NO_OF_RESPONSES 10
#define INQUIRY_DURATION    10000
#define INQUIRY_TYPE        2
#define MAX_NAME_LENGTH     10
#endif
#else
#define RSI_BT_LOCAL_NAME (void *)"SPP_SLAVE" //! Module name
#endif
#define PIN_CODE "0000"

#define RSI_OPERMODE_WLAN_BT_CLASSIC 9

/***********************************************************************************************************************************************/
//! application events list
/***********************************************************************************************************************************************/
#define RSI_APP_EVENT_CONNECTED    1
#define RSI_APP_EVENT_PINCODE_REQ  2
#define RSI_APP_EVENT_LINKKEY_SAVE 3
#define RSI_APP_EVENT_AUTH_COMPLT  4
#define RSI_APP_EVENT_DISCONNECTED 5
#define RSI_APP_EVENT_LINKKEY_REQ  6
#define RSI_APP_EVENT_SPP_CONN     7
#define RSI_APP_EVENT_SPP_DISCONN  8
#define RSI_APP_EVENT_SPP_RX       9
/** ssp related defines********/
#define RSI_APP_EVENT_PASSKEY_DISPLAY 10
#define RSI_APP_EVENT_PASSKEY_REQUEST 11
#define RSI_APP_EVENT_SSP_COMPLETE    12
#define RSI_APP_EVENT_CONFIRM_REQUEST 13
#define RSI_APP_EVENT_REMOTE_NAME_REQ 14
#define RSI_APP_EVENT_INQUIRY_COMPLT  15
#include <rsi_bt_common_config.h>
#endif
