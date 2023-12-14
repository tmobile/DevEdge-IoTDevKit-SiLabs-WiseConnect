/*
 * Copyright (c) 2021 T-Mobile USA, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#ifndef RSI_BT_CONFIG_H
#define RSI_BT_CONFIG_H


#include <rsi_data_types.h>
#include <rsi_bt_common.h>
#include <rsi_bt_common_config.h>

#undef RSI_BT_FEATURE_BITMAP
#define RSI_BT_FEATURE_BITMAP  (BT_RF_TYPE | ENABLE_BLE_PROTOCOL | BT_BDR_MODE_LP_CHAIN_ENABLE)

#define RSI_HAND_SHAKE_TYPE GPIO_BASED
#define RSI_FEATURE_BIT_MAP FEAT_ULP_GPIO_BASED_HANDSHAKE

#ifndef CONFIG_WISECONNECT_WIFI
#undef RSI_EXT_CUSTOM_FEATURE_BIT_MAP
#define RSI_EXT_CUSTOM_FEATURE_BIT_MAP (EXT_FEAT_LOW_POWER_MODE | BIT(31))
#endif /* CONFIG_WISECONNECT_WIFI */

#endif

