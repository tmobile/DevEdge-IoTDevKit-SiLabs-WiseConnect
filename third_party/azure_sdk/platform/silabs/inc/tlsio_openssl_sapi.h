/*******************************************************************************
* @file  tlsio_openssl_rs9116.h
* @brief 
*******************************************************************************
* Copyright (c) Microsoft. All rights reserved.
* Licensed under the MIT license. See LICENSE file in the project root for full license information.
******************************************************************************
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
#ifndef TLSIO_SSL_H
#define TLSIO_SSL_H

#include "azure_c_shared_utility/xio.h"
#include "umock_c/umock_c_prod.h"

#ifdef __cplusplus
extern "C" {
#include <cstddef>
#else
#include <stddef.h>
#endif /* __cplusplus */

const IO_INTERFACE_DESCRIPTION *tlsio_openssl_get_interface_description(void);
CONCRETE_IO_HANDLE tlsio_ssl_create(void *io_create_parameters);
void tlsio_ssl_destroy(CONCRETE_IO_HANDLE tls_io);
int tlsio_ssl_open(CONCRETE_IO_HANDLE tls_io,
                   ON_IO_OPEN_COMPLETE on_io_open_complete,
                   void *on_io_open_complete_context,
                   ON_BYTES_RECEIVED on_bytes_received,
                   void *on_bytes_received_context,
                   ON_IO_ERROR on_io_error,
                   void *on_io_error_context);

int tlsio_ssl_close(CONCRETE_IO_HANDLE tls_io, ON_IO_CLOSE_COMPLETE on_io_close_complete, void *callback_context);

int tlsio_ssl_send(CONCRETE_IO_HANDLE tls_io,
                   const void *buffer,
                   size_t size,
                   ON_SEND_COMPLETE on_send_complete,
                   void *callback_context);

void tlsio_ssl_dowork(CONCRETE_IO_HANDLE tls_io);
int tlsio_ssl_setoption(CONCRETE_IO_HANDLE tls_io, const char *optionName, const void *value);
int tlsio_openssl_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TLSIO_SSL_H */
#endif

