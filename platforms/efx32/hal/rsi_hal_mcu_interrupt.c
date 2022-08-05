/*******************************************************************************
* @file  rsi_hal_mcu_interrupt.c
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
 * Includes
 */
#include "rsi_driver.h"
#include "em_gpio.h"
#include "em_usart.h"


typedef void (* UserIntCallBack_t)(void);
UserIntCallBack_t call_back, gpio_callback;
uint8_t current_pin_set, prev_pin_set;

/**************************************************************************//**
 * @brief
 *    GPIO interrupt handler.
 *****************************************************************************/
void GPIO_ODD_IRQHandler(void)
{
  if(call_back!=NULL)
    (*call_back)();

  GPIO_IntClear(0xAAAA);
#ifdef LOGGING_STATS
  current_pin_set = GPIO_PinInGet(LOGGING_STATS_PORT , LOGGING_STATS_PIN);
  if(prev_pin_set!= current_pin_set)
    {
      NVIC_DisableIRQ(GPIO_ODD_IRQn);
      NVIC_SetPriority(GPIO_ODD_IRQn, 5);
      if(gpio_callback!=NULL)
         (*gpio_callback)();
      GPIO_IntClear(0xAAAA);
      NVIC_EnableIRQ(GPIO_ODD_IRQn);
    }
  prev_pin_set = current_pin_set;
#endif
}

/*===================================================*/
/**
 * @fn           void rsi_hal_intr_config(void (* rsi_interrupt_handler)())
 * @brief        Starts and enables the SPI interrupt
 * @param[in]    rsi_interrupt_handler() ,call back function to handle interrupt
 * @param[out]   none
 * @return       none
 * @description  This HAL API should contain the code to initialize the register/pins
 *               related to interrupts and enable the interrupts.
 */
void rsi_hal_intr_config(void (* rsi_interrupt_handler)(void))
{
  call_back = rsi_interrupt_handler;
  return;
}

/*===================================================*/
/**
 * @fn           void rsi_hal_log_stats_intr_config(void (* rsi_give_wakeup_indication)())
 * @brief        Checks the interrupt and map/set gpio callback function
 * @param[in]    rsi_give_wakeup_indication() ,gpio call back function to handle interrupt
 * @param[out]   none
 * @return       none
 * @description  This HAL API should contain the code
 *               related to mapping of gpio callback function.
 */
#ifdef LOGGING_STATS
void rsi_hal_log_stats_intr_config(void (* rsi_give_wakeup_indication)())
{
    gpio_callback = rsi_give_wakeup_indication;
}
#endif
/*===================================================*/
/**
 * @fn           void rsi_hal_intr_mask(void)
 * @brief        Disables the SPI Interrupt
 * @param[in]    none
 * @param[out]   none
 * @return       none
 * @description  This HAL API should contain the code to mask/disable interrupts.
 */
void rsi_hal_intr_mask(void)
{
  // Mask/Disable the interrupt
  NVIC_DisableIRQ(GPIO_ODD_IRQn);
  return;
}


/*===================================================*/
/**
 * @fn           void rsi_hal_intr_unmask(void)
 * @brief        Enables the SPI interrupt
 * @param[in]    none
 * @param[out]   none
 * @return       none
 * @description  This HAL API should contain the code to enable interrupts.
 */
void rsi_hal_intr_unmask(void)
{
  // Unmask/Enable the interrupt
  NVIC_EnableIRQ(GPIO_ODD_IRQn);
  return;
}



/*===================================================*/
/**
 * @fn           void rsi_hal_intr_clear(void)
 * @brief        Clears the pending interrupt
 * @param[in]    none
 * @param[out]   none
 * @return       none
 * @description  This HAL API should contain the code to clear the handled interrupts.
 */
void rsi_hal_intr_clear(void)
{
  // Clear the interrupt

  return;

}


/*===================================================*/
/**
 * @fn          void rsi_hal_intr_pin_status(void)
 * @brief       Checks the SPI interrupt at pin level
 * @param[in]   none
 * @param[out]  uint8_t, interrupt status
 * @return      none
 * @description This API is used to check interrupt pin status(pin level whether it is high/low).
 */
uint8_t rsi_hal_intr_pin_status(void)
{
  volatile uint8_t status = 0;
  // Return interrupt pin  status(high(1) /low (0))
  status = rsi_hal_get_gpio(RSI_HAL_MODULE_INTERRUPT_PIN);
 // status = NVIC_GetPendingIRQ(GPIO_ODD_IRQn);

  return status;
}

/*===================================================*/
/**
 * @fn           rsi_reg_flags_t rsi_hal_critical_section_entry(void)
 * @brief        hold interrupt status and disables the SPI interrupt
 * @param[in]    none  
 * @param[out]   none
 * @return       stored interrupt status
 * @description  This HAL API should contain the code to hold interrupt status and disable interrupts.
 */
uint32_t rsi_hal_critical_section_entry(void)
{
	rsi_reg_flags_t xflags;

	// hold interrupt status before entering critical section
	xflags = NVIC_GetEnableIRQ(GPIO_ODD_IRQn);

	// disable interrupts	
	NVIC_DisableIRQ(GPIO_ODD_IRQn);

	// return stored interrupt status
	return (xflags);
}

/*===================================================*/
/**
 * @fn           void rsi_hal_critical_section_exit(void)
 * @brief        Enables the SPI interrupt
 * @param[in]    none  
 * @param[out]   none
 * @return       none
 * @description  This HAL API should contain the code to enable interrupts.
 */
void rsi_hal_critical_section_exit(void)
{
	NVIC_EnableIRQ(GPIO_ODD_IRQn);
}
