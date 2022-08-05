/*******************************************************************************
* @file  tlsio_rs9116.h
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
#ifndef TLSIO_H
#define TLSIO_H

#include "azure_c_shared_utility/xio.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct TLSIO_CONFIG_TAG {
  const char *hostname;
  int port;
  const IO_INTERFACE_DESCRIPTION *underlying_io_interface;
  void *underlying_io_parameters;
  int socket_id;
} TLSIO_CONFIG;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TLSIO_H */

#endif

