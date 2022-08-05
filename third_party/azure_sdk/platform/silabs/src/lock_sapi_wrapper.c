/*******************************************************************************
* @file  lock_sapi_wrapper.c
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

#include "azure_c_shared_utility/lock.h"
#include <stdlib.h>
#include "azure_c_shared_utility/gballoc.h"
#include "azure_c_shared_utility/xlogging.h"
#include "azure_macro_utils/macro_utils.h"
#include "rsi_driver.h"

LOCK_HANDLE Lock_Init(void)
{
  //! Codes_SRS_LOCK_10_002: [Lock_Init on success shall return a valid lock handle which should be a non NULL value] 
  //! Codes_SRS_LOCK_10_003: [Lock_Init on error shall return NULL ] 
  rsi_mutex_handle_t *result = (rsi_mutex_handle_t *)malloc(sizeof(rsi_mutex_handle_t));
  if (result == NULL) {
    LogError("malloc failed.");
  } else {
    if (rsi_mutex_create((uint32_t *)result) != RSI_ERROR_NONE) {
      LogError("rsi_mutex_create failed.");
      free(result);
      result = NULL;
    }
  }

  return (LOCK_HANDLE)result;
}

LOCK_RESULT Lock_Deinit(LOCK_HANDLE handle)
{
  LOCK_RESULT result;
  if (handle == NULL) {
    //! Codes_SRS_LOCK_10_007: [Lock_Deinit on NULL handle passed returns LOCK_ERROR] 
    LogError("Invalid argument; handle is NULL.");
    result = LOCK_ERROR;
  } else {
    //! Codes_SRS_LOCK_10_012: [Lock_Deinit frees the memory pointed by handle] 
    if (rsi_mutex_destroy((rsi_mutex_handle_t *)handle) == RSI_ERROR_NONE) {
      free(handle);
      handle = NULL;
      result = LOCK_OK;
    } else {
      LogError("pthread_mutex_destroy failed;");
      result = LOCK_ERROR;
    }
  }

  return result;
}

LOCK_RESULT Lock(LOCK_HANDLE handle)
{
  LOCK_RESULT result;
  if (handle == NULL) {
    //! Codes_SRS_LOCK_10_007: [Lock on NULL handle passed returns LOCK_ERROR] 
    LogError("Invalid argument; handle is NULL.");
    result = LOCK_ERROR;
  } else {
    //! AcquireSRWLockExclusive((SRWLOCK*)handle);
    if (rsi_mutex_lock((uint32_t *)handle) == RSI_ERROR_NONE) {
      //! Codes_SRS_LOCK_10_005: [Lock on success shall return LOCK_OK] 
      result = LOCK_OK;
    } else {
      //! Codes_SRS_LOCK_10_006: [Lock on error shall return LOCK_ERROR] 
      LogError("pthread_mutex_lock failed.");
      result = LOCK_ERROR;
    }
  }

  return result;
}

LOCK_RESULT Unlock(LOCK_HANDLE handle)
{
  LOCK_RESULT result;
  if (handle == NULL) {
    //! Codes_SRS_LOCK_10_007: [Unlock on NULL handle passed returns LOCK_ERROR] 
    LogError("Invalid argument; handle is NULL.");
    result = LOCK_ERROR;
  } else {
    if (rsi_mutex_unlock((uint32_t *)handle) == RSI_ERROR_NONE) {
      //! Codes_SRS_LOCK_10_009: [Unlock on success shall return LOCK_OK] 
      result = LOCK_OK;
    } else {
      //! Codes_SRS_LOCK_10_010: [Unlock on error shall return LOCK_ERROR] 
      LogError("pthread_mutex_unlock failed.");
      result = LOCK_ERROR;
    }
  }

  return result;
}
#endif

