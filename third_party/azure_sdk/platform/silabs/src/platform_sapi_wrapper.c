/*******************************************************************************
* @file  platform_sapi_wrapper.c
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
#include "azure_c_shared_utility/platform.h"
#include "azure_c_shared_utility/xio.h"
#include "azure_c_shared_utility/xlogging.h"
#include "tlsio_openssl_sapi.h"
#ifdef USE_OPENSSL
#include "tlsio_openssl.h"
#endif
#if USE_CYCLONESSL
#include "tlsio_cyclonessl.h"
#endif
#if USE_WOLFSSL
#include "tlsio_wolfssl.h"
#endif
#if USE_MBEDTLS
#include "tlsio_mbedtls.h"
#endif

#include <stdlib.h>

int platform_init(void)
{
  int result;
  result = tlsio_openssl_init();
  return result;
}

const IO_INTERFACE_DESCRIPTION *platform_get_default_tlsio(void)
{
#if USE_CYCLONESSL
  return tlsio_cyclonessl_get_interface_description();
#elif USE_WOLFSSL
  return tlsio_wolfssl_get_interface_description();
#elif USE_MBEDTLS
  return tlsio_mbedtls_get_interface_description();
#else
  //! Default to openssl
  return tlsio_openssl_get_interface_description();
#endif
}

STRING_HANDLE platform_get_platform_info(PLATFORM_INFO_OPTION options)
{
  //! This fucntionality is not needed 
  //! No applicable options, so ignoring parameter
  (void)options;
  //! Expected format: "(<runtime name>; <operating system name>; <platform>)"
  return STRING_construct("(native; undefined; undefined)");
}

void platform_deinit(void)
{

}
#endif

