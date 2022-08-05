/*
 * Copyright (c) 2021 T-Mobile USA, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#ifndef RSI_BLE_CONFIG_H
#define RSI_BLE_CONFIG_H

#include <rsi_data_types.h>
#include <rsi_ble_common_config.h>


#ifdef CONFIG_WISECONNECT_DISABLE_DEFAULT_SCAN_RESPONSE
#undef RSI_BLE_SET_SCAN_RESP_DATA_FROM_HOST
#if CONFIG_WISECONNECT_DISABLE_DEFAULT_SCAN_RESPONSE
#define RSI_BLE_SET_SCAN_RESP_DATA_FROM_HOST 1
#else 
#define RSI_BLE_SET_SCAN_RESP_DATA_FROM_HOST 0
#endif
#endif

#ifdef CONFIG_WISECONNECT_DISABLE_DEFAULT_GAP_GATT
#undef BLE_SIMPLE_GATT
#if CONFIG_WISECONNECT_DISABLE_DEFAULT_GAP_GATT
#define BLE_SIMPLE_GATT 1
#else
#define BLE_SIMPLE_GATT 0
#endif
#endif

#ifdef CONFIG_WISECONNECT_BLE_MAX_CENTRALS
#undef RSI_BLE_MAX_NBR_MASTERS
#define RSI_BLE_MAX_NBR_MASTERS CONFIG_WISECONNECT_BLE_MAX_CENTRALS
#endif

#ifdef CONFIG_WISECONNECT_BLE_MAX_PERIPHERALS
#undef RSI_BLE_MAX_NBR_SLAVES
#define RSI_BLE_MAX_NBR_SLAVES CONFIG_WISECONNECT_BLE_MAX_PERIPHERALS
#endif

#ifdef CONFIG_WISECONNECT_BLE_MAX_SERVS
#undef RSI_BLE_MAX_NBR_ATT_SERV
#define RSI_BLE_MAX_NBR_ATT_SERV CONFIG_WISECONNECT_BLE_MAX_SERVS
#endif

#ifdef CONFIG_WISECONNECT_BLE_MAX_CHARS
#undef RSI_BLE_MAX_NBR_ATT_REC
#define RSI_BLE_MAX_NBR_ATT_REC CONFIG_WISECONNECT_BLE_MAX_CHARS
#endif

#ifdef CONFIG_WISECONNECT_BLE_MTU
#undef RSI_BLE_MTU_SIZE
#define RSI_BLE_MTU_SIZE CONFIG_WISECONNECT_BLE_MTU
#endif

#endif
