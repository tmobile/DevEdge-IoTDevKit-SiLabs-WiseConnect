/*******************************************************************************
* @file  rsi_common_config.h
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
 * @file         rsi_common_config.h
 * @version      0.1
 * @date         19 Mar 2021*
 *
 *
 *  @brief : This file contains user configurable details to configure the device
 *
 *  @section Description  This file contains user configurable details to configure the device
 */

#ifndef RSI_APP_COMMON_CONFIG_H
#define RSI_APP_COMMON_CONFIG_H
#include <stdio.h>
#include "rsi_ble_config.h"

/*=======================================================================*/
//   ! MACROS
/*=======================================================================*/

//! opermode selection
#define RSI_COEX_MODE 13

//! Application Task priorities
#define RSI_BLE_MAIN_TASK_PRIORITY 2
#define RSI_BLE_APP_TASK_PRIORITY  1

//! Application Task sizes
#define RSI_BLE_APP_MAIN_TASK_SIZE (512 * 2)
#define RSI_BLE_APP_TASK_SIZE      (512 * 4)

/*=======================================================================*/
//   ! Data type declarations
/*=======================================================================*/

typedef struct rsi_parsed_conf_s {
  struct rsi_ble_config_t {
    rsi_ble_conn_config_t rsi_ble_conn_config[TOTAL_CONNECTIONS];
  } rsi_ble_config;
} rsi_parsed_conf_t;

/*=======================================================================*/
//   ! Function prototype declarations
/*=======================================================================*/
int32_t rsi_initiate_power_save(void);
void rsi_ble_main_app_task(void);
void rsi_ble_task_on_conn(void *parameters);
void rsi_ble_slave_app_task(void);
void rsi_common_app_task(void);
#endif
