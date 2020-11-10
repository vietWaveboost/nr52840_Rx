/**
 * GPIO implementations on Nordic SDK15.
 *
 * License: BSD-3
 * Author: Otso Jousimaa <otso@ojousima.net>
 */

#include "ruuvi_platform_external_includes.h"
#if NRF5_SDK15_GPIO_ENABLED
#include "ruuvi_interface_gpio.h"
#include "ruuvi_driver_error.h"
#include "nrf_gpio.h"
#include <stdbool.h>

// No implementation required.
ruuvi_driver_status_t ruuvi_platform_gpio_init(void)
{
  return RUUVI_DRIVER_SUCCESS;
}

ruuvi_driver_status_t ruuvi_platform_gpio_configure(uint8_t pin, ruuvi_interface_gpio_mode_t mode)
{
  if(RUUVI_INTERFACE_GPIO_PIN_UNUSED == pin) { return RUUVI_DRIVER_SUCCESS; }
  switch (mode)
  {
  case RUUVI_INTERFACE_GPIO_MODE_HIGH_Z:
    nrf_gpio_cfg_default(pin);
    break;

  case RUUVI_INTERFACE_GPIO_MODE_INPUT_NOPULL:
    nrf_gpio_cfg_input (pin, NRF_GPIO_PIN_NOPULL);
    break;

  case RUUVI_INTERFACE_GPIO_MODE_INPUT_PULLUP:
    nrf_gpio_cfg_input (pin, NRF_GPIO_PIN_PULLUP);
    break;

  case RUUVI_INTERFACE_GPIO_MODE_INPUT_PULLDOWN:
    nrf_gpio_cfg_input (pin, NRF_GPIO_PIN_PULLDOWN);
    break;

  case RUUVI_INTERFACE_GPIO_MODE_OUTPUT_STANDARD:
    nrf_gpio_cfg_output (pin);
    break;

  case RUUVI_INTERFACE_GPIO_MODE_OUTPUT_HIGHDRIVE:
    nrf_gpio_cfg (pin,
                  NRF_GPIO_PIN_DIR_OUTPUT,
                  NRF_GPIO_PIN_INPUT_DISCONNECT,
                  NRF_GPIO_PIN_NOPULL,
                  NRF_GPIO_PIN_H0H1,
                  NRF_GPIO_PIN_NOSENSE);
    break;

  default:
    return RUUVI_DRIVER_ERROR_INVALID_PARAM;
  }
  return RUUVI_DRIVER_SUCCESS;
}

ruuvi_driver_status_t ruuvi_platform_gpio_toggle(uint8_t pin)
{
    nrf_gpio_pin_toggle(pin);
    return RUUVI_DRIVER_SUCCESS;
}

ruuvi_driver_status_t ruuvi_platform_gpio_write(uint8_t pin, ruuvi_interface_gpio_state_t state)
{
  if(RUUVI_INTERFACE_GPIO_HIGH == state) { nrf_gpio_pin_set(pin);   }
  if(RUUVI_INTERFACE_GPIO_LOW  == state) { nrf_gpio_pin_clear(pin); }
  return RUUVI_DRIVER_SUCCESS;
}

ruuvi_driver_status_t ruuvi_platform_gpio_read(uint8_t pin, ruuvi_interface_gpio_state_t* state)
{
  if(NULL == state) { return RUUVI_DRIVER_ERROR_NULL; }
  bool high = nrf_gpio_pin_read(pin);
  if(true == high)  { *state = RUUVI_INTERFACE_GPIO_HIGH; }
  if(false == high) { *state = RUUVI_INTERFACE_GPIO_LOW;  }
  return RUUVI_DRIVER_SUCCESS;
}

#endif