#include "ruuvi_platform_external_includes.h"
#if NRF5_SDK15_SCHEDULER_ENABLED

#include "ruuvi_driver_error.h"
#include "ruuvi_interface_scheduler.h"
#include "sdk_errors.h"
#include "app_scheduler.h"

// Ignore give parameters to call the macro with #defined constants
ruuvi_driver_status_t ruuvi_interface_scheduler_init(size_t event_size, size_t queue_length)
{
  // Event size and queue length must be fixed at compile time. Warn user if other values are going to be used.
  if(event_size != NRF5_SDK15_SCHEDULER_DATA_MAX_SIZE || queue_length != NRF5_SDK15_SCHEDULER_QUEUE_MAX_LENGTH)
  { RUUVI_DRIVER_ERROR_CHECK(RUUVI_DRIVER_ERROR_INVALID_PARAM, ~RUUVI_DRIVER_ERROR_FATAL); }

  APP_SCHED_INIT(NRF5_SDK15_SCHEDULER_DATA_MAX_SIZE, NRF5_SDK15_SCHEDULER_QUEUE_MAX_LENGTH);
  return RUUVI_DRIVER_SUCCESS;
}

ruuvi_driver_status_t ruuvi_platform_scheduler_execute (void)
{
  app_sched_execute();
  return RUUVI_DRIVER_SUCCESS;
}

ruuvi_driver_status_t ruuvi_platform_scheduler_event_put (void const *p_event_data, uint16_t event_size, ruuvi_scheduler_event_handler_t handler)
{
  ret_code_t err_code = app_sched_event_put(p_event_data, event_size, (app_sched_event_handler_t) handler);
  return ruuvi_platform_to_ruuvi_error(&err_code);
}

#endif