/*******************************************************************************
* @file  tickcounter_sapi_wrapper.c
* @brief 
*******************************************************************************
* Copyright (c) Microsoft. All rights reserved.
* Licensed under the MIT license. See LICENSE file in the project root for full license information.
*
*******************************************************************************
*
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
#ifdef AZURE_ENABLE
#include <stdlib.h>
#include "azure_c_shared_utility/gballoc.h"
#include <stdint.h>
#include "azure_c_shared_utility/tickcounter.h"
#include "azure_c_shared_utility/optimize_size.h"
#include "azure_c_shared_utility/xlogging.h"
#include "time.h"
#include "rsi_hal.h"
#include "rsi_timer.h"

typedef struct TICK_COUNTER_INSTANCE_TAG {
  time_t init_time_value;
  tickcounter_ms_t current_ms;
} TICK_COUNTER_INSTANCE;

TICK_COUNTER_HANDLE tickcounter_create(void)
{

  TICK_COUNTER_INSTANCE *result = (TICK_COUNTER_INSTANCE *)malloc(sizeof(TICK_COUNTER_INSTANCE));
  if (result == NULL) {
    LogError("Failed creating tick counter");
  }
  return result;
}

void tickcounter_destroy(TICK_COUNTER_HANDLE tick_counter)
{
  if (tick_counter != NULL) {
    free(tick_counter);
  }
}

int tickcounter_get_current_ms(TICK_COUNTER_HANDLE tick_counter, tickcounter_ms_t *current_ms)
{
  int result;

  if (tick_counter == NULL || current_ms == NULL) {
    LogError("tickcounter failed: Invalid Arguments.");
    result = MU_FAILURE;
  } else {
    *current_ms = rsi_timer_read_counter();
    result      = 0;
  }

  return result;
}
#endif

