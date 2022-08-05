/*******************************************************************************
* @file  azure_iot_config.h
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
 * @file         azure_iot_config.h
 * @version      0.1
 * @date         22 May 2021
 * @brief        This file contains user configurable details to configure the device  
 *
 *
 */
#ifndef AZURE_IOT_CONFIG_H_
#define AZURE_IOT_CONFIG_H_

/* ========================================================== */
#define MAX_NW_RETRY_COUNT  5      ///< Network retry count value
#define MAX_NTP_RETRY_COUNT 5      ///< NTP retry count value
#define RECV_TIMEOUT_VAL    5000   ///< rsi_recv() Time Out in ms
#define TIMEOUT_VAL_NTP_MS  1000   ///< NTP Time Out in ms
#define NTP_SERVER_PORT     123    ///< NTP Port
#define DNS_REQ_COUNT       5      ///< DNS REQUEST retry Count
#define MQTT_KEEPALIVE_VAL  4 * 60 ///< MQTT Keepalive value
// Connection string used for azure connectivity. For Self signed authentication connection string to be provided in below format
// For symmetric key authentication consider the primary key of device i.e
// "HostName=example.azure-devices.net;DeviceId=example_Device_SymKey;SharedAccessKey=xxxxxx";
#define CONNECTION_STRING "HostName=xxxxxx.azure-devices.net;DeviceId=xxxxxxx;x509=true"

#define MESSAGE_COUNT \
  5 ///< Number of D2C messages sent to Azure Hub and also minimum number of C2D messages to be received by application
#define CLIENT_PORT 4002 ///< Client port
/* =========================================================== */

#endif /* End of AZURE_IOT_CONFIG_H_*/
