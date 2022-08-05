/*******************************************************************************
* @file  rsi_multicast.c
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

#include "rsi_driver.h"
#include "rsi_multicast.h"
/** @addtogroup NETWORK3
* @{
*/
/*==============================================*/
/**
 * @brief       According to command type, this API will send multicast group join or leave. This is a blocking API.
 * @param[in]   flags          -  Select version use BIT(0) : 0 - IPv4 , 1 - IPv6
 * @param[in]   ip_address     - Multicast IP address
 * @param[in]   command_type   - Type of commands: JOIN/LEAVE
 * @return      0              -  Success \n
 *              Negative value -  Failure
 *
 */
/// @private
static int32_t rsi_multicast(uint8_t flags, int8_t *ip_address, uint8_t command_type)
{
  int32_t status = RSI_SUCCESS;
  SL_PRINTF(SL_MULTICAST_ENTRY, NETWORK, LOG_INFO);

  rsi_pkt_t *pkt;
  rsi_req_multicast_t *multicast;

  // Get WLAN CB structure pointer
  rsi_wlan_cb_t *wlan_cb = rsi_driver_cb->wlan_cb;

  status = rsi_check_and_update_cmd_state(NWK_CMD, IN_USE);
  if (status == RSI_SUCCESS) {

    // Allocate command buffer from WLAN pool
    pkt = rsi_pkt_alloc(&wlan_cb->wlan_tx_pool);
    // If allocation of packet fails
    if (pkt == NULL) {
      // Change common state to allow state
      rsi_check_and_update_cmd_state(NWK_CMD, ALLOW);

      // Return packet allocation failure error
      SL_PRINTF(SL_MULTICAST_PKT_ALLOCATION_FAILURE, NETWORK, LOG_ERROR);
      return RSI_ERROR_PKT_ALLOCATION_FAILURE;
    }

    multicast = (rsi_req_multicast_t *)pkt->data;

    // Fill IP version and IP address
    if (flags & RSI_IPV6) {
      // Fill IPv6 version
      rsi_uint16_to_2bytes(multicast->ip_version, RSI_IP_VERSION_6);

      // Fill IPv6 address
      memcpy(multicast->multicast_address.ipv6_address, ip_address, RSI_IPV6_ADDRESS_LENGTH);
    } else {
      // Fill IPv4 version
      rsi_uint16_to_2bytes(multicast->ip_version, RSI_IP_VERSION_4);

      // Fill IPv4 address
      memcpy(multicast->multicast_address.ipv4_address, ip_address, RSI_IPV4_ADDRESS_LENGTH);
    }

    // Fill command type
    rsi_uint16_to_2bytes(multicast->type, command_type);

#ifndef RSI_NWK_SEM_BITMAP
    rsi_driver_cb_non_rom->nwk_wait_bitmap |= BIT(0);
#endif

    // Send set FTP Create command
    status = rsi_driver_wlan_send_cmd(RSI_WLAN_REQ_MULTICAST, pkt);

    // Wait on NWK semaphore
    rsi_wait_on_nwk_semaphore(&rsi_driver_cb_non_rom->nwk_sem, RSI_MULTICAST_RESPONSE_WAIT_TIME);
    // Get WLAN/network command response status
    status = rsi_wlan_get_nwk_status();

    // Change NWK state to allow
    rsi_check_and_update_cmd_state(NWK_CMD, ALLOW);

  } else {
    // Return NWK command error
    SL_PRINTF(SL_MULTICAST_NWK_COMMAND_ERROR, NETWORK, LOG_ERROR, "status: %4x", status);
    return status;
  }

  // Return status if error in sending command occurs
  SL_PRINTF(SL_MULTICAST_EXIT, NETWORK, LOG_INFO, "status: %4x", status);
  return status;
}

/** @} */

/** @addtogroup NETWORK3
* @{
*/
/*==============================================*/
/**
 * @brief       Join to a multicast group. This is a blocking API.
 * @pre         \ref rsi_config_ipaddress() API needs to be called before this API.
 * @param[in]   flags          - Select the IP version. \n
 *                     BIT(0)  – RSI_IPV6.Set this bit to enable IPv6. By default it is configured to IPv4.
 * @param[in]   ip_address     - IPv4/IPv6 address of multicast group.
 * @return	             0 - Success \n
 *              Negative Value - Failure \n
 *                          -3 - Command given in wrong state \n
 *                          -4 - Buffer not available to serve the command
 * @note       Device supports only one Multicast group. \n
 *             Must leave the previous group, if joining a new Multicast group
 */
int32_t rsi_multicast_join(uint8_t flags, int8_t *ip_address)
{
  int32_t status = RSI_SUCCESS;
  SL_PRINTF(SL_MULTICAST_JOIN_ENTRY, NETWORK, LOG_INFO);

  status = rsi_multicast(flags, ip_address, RSI_MULTICAST_JOIN);
  SL_PRINTF(SL_MULTICAST_JOIN_EXIT, NETWORK, LOG_INFO, "status: %4x", status);
  return status;
}

/** @} */

/** @addtogroup NETWORK3
* @{
*/
/*==============================================*/
/**
 * @brief       Leave the multicast group. This is a blocking API.
 * @pre         \ref rsi_config_ipaddress() API needs to be called before this API. 
 * @param[in]   flags          - Select the IP version. \n
 *                      BIT(0) – RSI_IPV6. Set this bit to enable IPv6. By default it is configured to IPv4.
 * @param[in]   ip_address     - IPv4/IPv6 address of multicast group. 
 * @return      0              - Success \n
 *              Negative Value - Failure \n
 *              -3 - Command given in wrong state \n
 *              -4 - Buffer not available to serve the command \n 
 *
 *                               If return value is greater than 0 \n
 *                               0x0021,0x002C,0x0015,0xBB16,0xBB17
 * @note             Device supports only one Multicast group. \n
 *                   Must leave the previous group, if joining a new Multicast group
 *                   Refer to Error Codes section for the description of the above error codes \ref error-codes.
 */
int32_t rsi_multicast_leave(uint8_t flags, int8_t *ip_address)
{
  int32_t status = RSI_SUCCESS;
  SL_PRINTF(SL_MULTICAST_LEAVE_ENTRY, NETWORK, LOG_INFO);

  status = rsi_multicast(flags, ip_address, RSI_MULTICAST_LEAVE);

  SL_PRINTF(SL_MULTICAST_LEAVE_EXIT, NETWORK, LOG_INFO, "status: %4x", status);
  return status;
}
/** @} */
