/*******************************************************************************
* @file sl_rsi_host_api.h
* @brief
*******************************************************************************
* # License
* <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com
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
#include <stdio.h>
#include <stdlib.h>

#include "sdiodrv.h"
#include "sl_status.h"

/**
 * @brief SDIO block size
 * @warning This should be configured from the Bus SDIO plugin options.
 */
#ifndef SL_RSI_SDIO_BLOCK_SIZE
#define SL_RSI_SDIO_BLOCK_SIZE            256
#endif

/* SDIO CCCR register offsets */
#define SL_RSI_SDIO_CCCR_IO_QUEUE_ENABLE        (0x02)
#define SL_RSI_SDIO_CCCR_IOR_ENABLE             (0x03)
#define SL_RSI_SDIO_CCCR_IRQ_ENABLE             (0x04)
#define SL_RSI_SDIO_CCCR_BUS_INTERFACE_CONTROL  (0x07)
#define SL_RSI_SDIO_CCCR_HIGH_SPEED_ENABLE      (0x13)

/* SDIO FBR1 register offsets */
#define SL_RSI_SDIO_FBR1_BLOCK_SIZE_LSB (0x110)   /* Function 1 16-bit block size LSB */
#define SL_RSI_SDIO_FBR1_BLOCK_SIZE_MSB (0x111)   /* Function 1 16-bit block size MSB */

//typedef uint32_t sl_status_t;

//uint8_t sdio_init_done;

#define SL_RSI_ERROR_CHECK(__status__)               \
  do {                                               \
    if (((sl_status_t)__status__) != SL_STATUS_OK) { \
      goto error_handler;                            \
    }                                                \
  } while (0)

typedef enum {
  SL_RSI_BUS_WRITE = (1 << 0),
  SL_RSI_BUS_READ  = (1 << 1),
  SL_RSI_BUS_WRITE_AND_READ = SL_RSI_BUS_WRITE | SL_RSI_BUS_READ,
} sl_rsi_host_bus_transfer_type_t;

/* WF200 host bus API */
/**************************************************************************//**
 * @brief Initialize the host bus
 * @returns Returns SL_STATUS_OK if successful, SL_STATUS_FAIL otherwise
 *
 * @note Called once during the driver initialization phase
 *****************************************************************************/
sl_status_t sl_rsi_host_init_bus(void);

/**************************************************************************//**
 * @brief Deinitialize the host bus
 * @returns Returns SL_STATUS_OK if successful, SL_STATUS_FAIL otherwise
 *
 * @note Called if an error occurs during the initialization phase
 *****************************************************************************/
sl_status_t sl_rsi_host_deinit_bus(void);

/* RSI host SDIO bus API */
/**************************************************************************//**
 * @brief Send command 52 on the SDIO bus
 *
 * @param type is the type of bus action (see ::sl_wfx_host_bus_transfer_type_t)
 * @param function is the function to use in the SDIO command
 * @param address is the address to use in the SDIO command
 * @param buffer is a pointer to the buffer data
 * @returns Returns SL_STATUS_OK if successful, SL_STATUS_FAIL otherwise
 *****************************************************************************/
sl_status_t sl_rsi_host_sdio_transfer_cmd52(sl_rsi_host_bus_transfer_type_t type,
                                            uint8_t  function,
                                            uint32_t address,
                                            uint8_t *buffer);
/**************************************************************************//**
 * @brief Send command 53 on the SDIO bus
 *
 * @param type is the type of bus action (see ::slx_rsi_host_bus_transfer_type_t)
 * @param function is the function to use in the SDIO command
 * @param address is the address to use in the SDIO command
 * @param buffer is a pointer to the buffer data
 * @param buffer_length is the length of the buffer data
 * @returns Returns SL_STATUS_OK if successful, SL_STATUS_FAIL otherwise
 *****************************************************************************/
sl_status_t sl_rsi_host_sdio_transfer_cmd53(sl_rsi_host_bus_transfer_type_t type,
                                            uint8_t  function,
                                            uint32_t address,
                                            uint16_t *buffer,
                                            uint16_t buffer_length);

/**************************************************************************//**
 * @brief Enable the SDIO high-speed mode
 * @returns Returns SL_STATUS_OK if successful, SL_STATUS_FAIL otherwise
 *****************************************************************************/
sl_status_t sl_rsi_host_sdio_enable_high_speed_mode(void);

/**************************************************************************//**
 * @brief Enable the bus interrupt
 * @returns Returns SL_STATUS_OK if successful, SL_STATUS_FAIL otherwise
 *****************************************************************************/
sl_status_t sl_rsi_host_enable_platform_interrupt(void);

/**************************************************************************//**
 * @brief Disable the bus interrupt
 * @returns Returns SL_STATUS_OK if successful, SL_STATUS_FAIL otherwise
 *****************************************************************************/
sl_status_t sl_rsi_host_disable_platform_interrupt(void);
