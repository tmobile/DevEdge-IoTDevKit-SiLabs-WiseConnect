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

#ifndef RSI_BT_CONFIG_H
#define RSI_BT_CONFIG_H

#include <rsi_data_types.h>

/******************************************************
 * *                      Macros
 * ******************************************************/

//! WLAN + BT Classic coex mode
#define RSI_OPERMODE_WLAN_BT_CLASSIC 9

/*=======================================================================*/
//! Discovery command parameters
/*=======================================================================*/

//! Discovery mode
//! Start the discoverable mode
#define START_DISCOVERY 0x01
//! Start the limited discoverable mode
#define START_LIMITED_DISCOVERY 0x02
//! Stop the discoverable mode
#define STOP_DISCOVERY 0x00

/*=======================================================================*/
//! Connectability command parameters
/*=======================================================================*/

//! Connectable mode
//! Start the connectable mode
#define CONNECTABLE 0x01
//! Stop the connectable mode
#define NON_CONNECTABLE 0x00

/*=======================================================================*/
//!  Authentication command parameters
/*=======================================================================*/

//! Pair mode
//! Enable authentication
//#define RSI_ENABLE                                  0x01
//! Enable authentication
//#define RSI_DISABLE                                 0x00

/*=======================================================================*/
//!  SSP Confirmation command parameters
/*=======================================================================*/

//! Confimation type
//! Accept confirmation
#define ACCEPT 0x01
//! Reject confirmation
#define REJECT 0x00

/*=======================================================================*/
//!  BT classic profile enable BITS
/*=======================================================================*/
#define RSI_SPP_PROFILE_BIT   BIT(0)
#define RSI_A2DP_PROFILE_BIT  BIT(1)
#define RSI_AVRCP_PROFILE_BIT BIT(2)
#define RSI_HFP_PROFILE_BIT   BIT(3)
#define RSI_PBAP_PROFILE_BIT  BIT(4)

/*=======================================================================*/
//!  SSP Confirmation command parameters
/*=======================================================================*/

//! A2DP Profile Enable
//#define A2DP_PROFILE_ENABLE
//! A2DP profile enable -> set the 23 bit in bt_feature_bit_map

/*=======================================================================*/

#define RSI_BT_MAX_PAYLOAD_SIZE \
  1010 /*In Stack MAX_ACL_PKT_LEN is 1010*/ //310 /* Max supported is 200, but 190 gives optimum Tx throughput */
#define BT_BDR_MODE 0                       // 1 - HP chain

#endif
