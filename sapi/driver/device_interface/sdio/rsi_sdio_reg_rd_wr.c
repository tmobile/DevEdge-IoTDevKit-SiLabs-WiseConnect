/*******************************************************************************
* @file  rsi_sdio_reg_rd_wr.c
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
 * @file    rsi_spi_reg_rd_wr.c
 * @version	0.1
 * @date 		15 Aug 2015
 *
 *
 *
 * @brief SDIO REGRDWR: SDIO Register Read/Write functions
 *
 *
 *
 */

/*
  Includes
 */
#include "rsi_driver.h"
#ifdef RSI_SDIO_INTERFACE
/*
  Global Variables
 */
/** @addtogroup DRIVER1
* @{
*/
/**
 *
 */
int16_t rsi_reg_rd(uint8_t regAddr, uint8_t *dBuf)
{
  return sdio_reg_readb(regAddr, dBuf);
}

/**
 */

int16_t rsi_reg_wr(uint8_t regAddr, uint8_t *dBuf)
{
  return sdio_reg_writeb(regAddr, dBuf);
}

#endif
/** @} */
