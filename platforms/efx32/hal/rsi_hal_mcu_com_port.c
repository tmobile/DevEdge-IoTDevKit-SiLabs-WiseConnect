/*******************************************************************************
* @file  rsi_hal_mcu_uart.c
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
 * Includes
 */
#include "rsi_driver.h"
#include "em_device.h"
#include "em_usart.h"
#include "rsi_board_configuration.h"


/*==================================================================*/
/**
 * @fn         int16_t rsi_uart_send(uint8_t *ptrBuf,uint16_t bufLen)
 * @param[in]  uint8 *ptrBuf, pointer to the buffer with the data to be sent/received
 * @param[in]  uint16 bufLen, number of bytes to send
 * @param[out] None
 * @return     0, 0=success
 * @section description
 * This API is used to send data to the Wi-Fi module through the UART interface.
 */
int16_t rsi_com_port_send(uint8_t *buffer, uint16_t buffer_length)
{
  for (int txCount = 0; txCount < buffer_length; txCount++) {
      USART_Tx(COM_PORT_PERIPHERAL, *buffer++);
    }
  return 0;
}


/*==================================================================*/
/**
 * @fn         int16_t rsi_uart_recv(uint8_t *ptrBuf,uint16_t bufLen)
 * @param[in]  uint8_t *ptrBuf, pointer to the buffer with the data to be sent/received
 * @param[in]  uint16_t bufLen, number of bytes to send
 * @param[out] None
 * @return     0, 0=success
 * @description
 * This API is used to receive data from Wi-Fi module through the UART interface.
 */


int16_t rsi_com_port_receive(uint8_t *buffer, uint16_t buffer_length)
{
  for (; buffer_length > 0; --buffer_length) {
    *buffer++ = USART_Rx(COM_PORT_PERIPHERAL);
  }
  return 0;
}
