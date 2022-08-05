/*******************************************************************************
* @file  sl_hal_mcu_logging.c
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
 * Includes
 */
#include "rsi_driver.h"


/*==================================================================*/
/**
 * @fn         int32_t sl_hal_send_log(uint8_t *buffer, uint32_t buffer_length)
 * @param[in]  uint8_t *buffer, pointer to buffer
 * @param[in]  uint32_t buffer_length, number of bytes to send
 * @param[out] None
 * @return     0, 0=success
 * @section description
 * This API is used to send data to logging interface 
 */
int32_t sl_hal_send_log(uint8_t *buffer, uint32_t buffer_length)
{
  // insert the token for identification
  LOG_PRINT("\r\n#@$ ");
  for (int txCount = 0; txCount < (int)buffer_length; txCount++){
    LOG_PRINT("%02x ", *(buffer++));
  }
  LOG_PRINT("\r\n");
  return 0;
}
