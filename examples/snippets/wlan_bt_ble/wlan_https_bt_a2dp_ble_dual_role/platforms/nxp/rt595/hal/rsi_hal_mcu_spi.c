/*******************************************************************************
* @file  rsi_hal_mcu_spi.c
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


#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_spi_cmsis.h"
#include "board.h"

#include "pin_mux.h"
#include "fsl_inputmux.h"
/**
 * Global Variables
 */
 



#if 0//def MXRT_595s
/*==================================================================*/
/**
 * @fn         int16_t rsi_spi_transfer(uint8_t *ptrBuf,uint16_t bufLen,uint8_t *valBuf,uint8_t mode)
 * @param[in]  uint8_t *tx_buff, pointer to the buffer with the data to be transfered
 * @param[in]  uint8_t *rx_buff, pointer to the buffer to store the data received
 * @param[in]  uint16_t transfer_length, Number of bytes to send and receive
 * @param[in]  uint8_t mode, To indicate mode 8 BIT/32 BIT mode transfers.
 * @param[out] None
 * @return     0, 0=success
 * @section description  
 * This API is used to tranfer/receive data to the Wi-Fi module through the SPI interface.
 */
int16_t rsi_spi_transfer(uint8_t *tx_buff, uint8_t *rx_buff, uint16_t transfer_length,uint8_t mode)
{
  
     isTransferCompleted = false;
    /* Start master transfer, send data to slave */
    DRIVER_MASTER_SPI.Transfer(tx_buff, rx_buff, transfer_length);
    
	/* Wait until transfer completed */
	while(!isTransferCompleted)
	{
	}


  return 0;
}
#endif

