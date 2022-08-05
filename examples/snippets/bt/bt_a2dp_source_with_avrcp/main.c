/*******************************************************************************
 * @file  main.c
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
 * @file    main.c
 * @version 0.1
 * @date    01 Feb 2021
 *
 *
 *
 *  @brief : This file contains driver initialization and application task creations 
 *
 *  @section Description  This file contains driver, application task initializations
 */

/*=======================================================================*/
//  ! INCLUDES
/*=======================================================================*/
#include <stdio.h>
#include <string.h>
#include "rsi_driver.h"

/*=======================================================================*/
//   ! MACROS
/*=======================================================================*/
#define RSI_DRIVER_TASK_PRIORITY   2 //! Wireless driver task priority
#define RSI_BT_TASK_PRIORITY       1
#define RSI_DRIVER_TASK_STACK_SIZE (512 * 2) //! Wireless driver task stack size
#define RSI_BT_TASK_STACK_SIZE     (512 * 2)
#define RSI_SBC_ENCODE_STACK_SIZE  (512 * 2)

#define GLOBAL_BUFF_LEN 50000 //! Memory length of driver
#define RSI_FOREVER     1

/*=======================================================================*/
//   ! GLOBAL VARIABLES
/*=======================================================================*/
rsi_task_handle_t driver_task_handle = NULL;
rsi_task_handle_t bt_task_handle     = NULL;
//! Memory to initialize driver
uint8_t global_buf[GLOBAL_BUFF_LEN] = { 0 };

/*=======================================================================*/
//   ! EXTERN VARIABLES
/*=======================================================================*/

/*=======================================================================*/
//   ! EXTERN FUNCTIONS
/*=======================================================================*/
extern int32_t rsi_bt_app_task();

/*=======================================================================*/
//   ! PROCEDURES
/*=======================================================================*/

/*====================================================*/
/**
 * @fn         int main(void)
 * @brief      starting point of application
 * @param[in]  none
 * @return     status
 *=====================================================*/

int main(void)
{
  int32_t status = RSI_SUCCESS;

  //! Driver initialization
  status = rsi_driver_init(global_buf, GLOBAL_BUFF_LEN);
  if ((status < 0) || (status > GLOBAL_BUFF_LEN)) {
    return status;
  }

#ifdef RSI_WITH_OS
  //! OS case

  //! Task created for BT protocol task
  rsi_task_create((void *)rsi_bt_app_task,
                  (uint8_t *)"bt_task",
                  RSI_BT_TASK_STACK_SIZE + RSI_SBC_ENCODE_STACK_SIZE,
                  NULL,
                  RSI_BT_TASK_PRIORITY,
                  &bt_task_handle);

  //! Task created for Driver task
  rsi_task_create((rsi_task_function_t)rsi_wireless_driver_task,
                  (uint8_t *)"driver_task",
                  RSI_DRIVER_TASK_STACK_SIZE,
                  NULL,
                  RSI_DRIVER_TASK_PRIORITY,
                  &driver_task_handle);

  //! OS TAsk Start the scheduler
  rsi_start_os_scheduler();
#else
  //! SiLabs module initialization
  status = rsi_device_init(LOAD_NWP_FW);
  if (status != RSI_SUCCESS) {
    return status;
  }

  //! WiSeConnect initialization
  status = rsi_wireless_init(RSI_WLAN_MODE, RSI_COEX_MODE);
  if (status != RSI_SUCCESS) {
    return status;
  }

  //! Send Feature frame
  status = rsi_send_feature_frame();
  if (status != RSI_SUCCESS) {
    return status;
  }
  while (RSI_FOREVER) {
    //! Execute demo
    rsi_bt_app_task();

    //! wireless driver task
    rsi_wireless_driver_task();
  }
#endif

  return 0;
}
