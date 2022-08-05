/*******************************************************************************
* @file  threadapi_sapi_wrapper.c
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
#include <stdint.h>
#include <stdlib.h>
#include "azure_c_shared_utility/threadapi.h"
#include "azure_c_shared_utility/xlogging.h"

MU_DEFINE_ENUM_STRINGS(THREADAPI_RESULT, THREADAPI_RESULT_VALUES);

THREADAPI_RESULT ThreadAPI_Create(THREAD_HANDLE *threadHandle, THREAD_START_FUNC func, void *arg)
{
  LogError("RS9116 does not support multi-thread function.");
  return THREADAPI_OK;
}

THREADAPI_RESULT ThreadAPI_Join(THREAD_HANDLE threadHandle, int *res)
{
  LogError("RS9116 does not support multi-thread function.");
  return THREADAPI_ERROR;
}

void ThreadAPI_Exit(int res)
{
  
}

void ThreadAPI_Sleep(unsigned int milliseconds)
{
  
}
#endif

