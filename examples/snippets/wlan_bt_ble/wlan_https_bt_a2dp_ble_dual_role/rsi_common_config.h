/*******************************************************************************
* @file  rsi_common_app_DEMO_57.h
* @brief 
*******************************************************************************
* # License
* Copyright 2020 Silicon Laboratories Inc. http://www.silabs.com/
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
 * @file         rsi_common_app_DEMO_57.h
 * @version      0.1
 * @date         01 Feb 2020*
 *
 *
 *  @brief : This file contains user configurable details to configure the device
 *
 *  @section Description  This file contains user configurable details to configure the device
 */

#ifndef SAPIS_EXAMPLES_RSI_DEMO_APPS_INC_RSI_COMMON_APP_DEMO_57_H
#define SAPIS_EXAMPLES_RSI_DEMO_APPS_INC_RSI_COMMON_APP_DEMO_57_H
#include <rsi_common_app.h>
//#if COEX_MAX_APP
#include <stdio.h>
#include <rsi_os.h>
#include <rsi_ble_device_info.h>

/*=======================================================================*/
//   ! MACROS
/*=======================================================================*/
//! Transient WLAN CoEx cases.
#define WLAN_TRANSIENT_CASE 0 //!Test Head
#if WLAN_TRANSIENT_CASE
#define WLAN_POWER_SAVE_USAGE    0
#define WLAN_TRANSIENT_SCAN_CASE 1 //! Head 1st category
#define WLAN_TRANSIENT_SYNC_CASE 0 //! Head 2nd category
#if WLAN_TRANSIENT_SCAN_CASE
#define DISABLE_ITER_COUNT 30
#elif WLAN_TRANSIENT_SYNC_CASE
#define DISABLE_ITER_COUNT 2
#endif
#endif

#define WLAN_SYNC_REQ \
  1 //! Enable this macro to start bt,ble and ant activites after wlan connection, else all activities starts concurrently
#define WLAN_STA_TX_CASE 0 //for WIFI_TCP_TX_POWERSAVE
//! Application Task priorities
#define RSI_BLE_MAIN_TASK_PRIORITY            2
#define RSI_BT_APP_TASK_PRIORITY              2 //! BT & BLE with Same Priority Fixes some basic issues.
#define RSI_HTTP_SOCKET_TASK_PRIORITY         1 //2
#define RSI_CERT_BYPASS_TASK_PRIORITY         1
#define RSI_WINDOW_RESET_NOTIFY_TASK_PRIORITY 1
#define RSI_BLE_APP_TASK_PRIORITY             1
#define RSI_ANT_APP_TASK_PRIORITY             0
#define RSI_WLAN_APP_TASK_PRIORITY            0

//! Application Task sizes
#define RSI_BLE_APP_MAIN_TASK_SIZE              (512 * 2)
#define RSI_BLE_APP_MASTER1_TASK_SIZE           (512 * 2)
#define RSI_BLE_APP_TASK_SIZE                   (512 * 4)
#define RSI_BT_APP_TASK_SIZE                    (512 * 2)
#define RSI_SBC_APP_ENCODE_SIZE                 (512 * 2)
#define RSI_ANT_APP_TASK_SIZE                   (512 * 2)
#define RSI_WLAN_APP_TASK_SIZE                  (512 * 2)
#define RSI_HTTP_SOCKET_TASK_STACK_SIZE         (512 * 2)
#define RSI_CERT_BYPASS_TASK_STACK_SIZE         (512 * 2)
#define RSI_WINDOW_RESET_NOTIFY_TASK_STACK_SIZE (512 * 2)
#define RSI_WLAN_TASK_STACK_SIZE                (512 * 2)

/*=======================================================================*/
//   ! GLOBAL VARIABLES
/*=======================================================================*/

typedef struct rsi_parsed_conf_s {
  struct rsi_protocol_sel_t {
    bool is_ble_enabled;
    bool is_bt_enabled;
    bool is_ant_enabled;
    bool is_wifi_enabled;
  } rsi_protocol_sel;
  struct rsi_ble_config_t {
    //		uint8_t no_of_slaves;
    //		uint8_t no_of_masters;
    //		uint8_t conn_by_name;
    //		uint8_t slave1_name[RSI_REM_DEV_NAME_LEN];
    //		uint8_t slave2_name[RSI_REM_DEV_NAME_LEN];
    //		uint8_t slave3_name[RSI_REM_DEV_NAME_LEN];
    //		uint8_t slave1_addr[RSI_REM_DEV_ADDR_LEN];
    //		uint8_t slave2_addr[RSI_REM_DEV_ADDR_LEN];
    //		uint8_t slave3_addr[RSI_REM_DEV_ADDR_LEN];
    rsi_ble_conn_config_t rsi_ble_conn_config[TOTAL_CONNECTIONS];
  } rsi_ble_config;
  //! To be defined
  struct rsi_bt_config_t {
    uint8_t *rsi_bd_addr;
    uint8_t rsi_app_avdtp_role;
    bool rsi_bt_avdtp_stats_enable;
    bool rsi_ta_based_encoder;
    bool rsi_bt_inquiry_enable;
    bool rsi_inq_rem_name_req;
    bool rsi_inq_conn_simultaneous;
  } rsi_bt_config;
} rsi_parsed_conf_t;

int32_t rsi_initiate_power_save(void);
int32_t set_power_config(void);
//#endif
#endif
