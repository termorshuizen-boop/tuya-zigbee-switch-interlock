#ifndef DEVICE_CONFIG_DEVICE_PARAMS_NV_H_
#define DEVICE_CONFIG_DEVICE_PARAMS_NV_H_

#include <stdint.h>

/*
 * Global device parameter: multi-press reset count.
 *   0  => multi-press factory reset disabled
 *   N  => factory-reset after N consecutive presses
 * Default: 10, persisted in NVM.
 */
extern uint8_t g_multi_press_reset_count;

/*
 * Global device parameter: interlocking state.
 *   0  => interlocking disabled
 *   1  => interlocking enabled
 * Default: 0, persisted in NVM.
 */
extern uint8_t g_interlocking_state;

void device_params_load_from_nv(void);
void device_params_set_multi_press_reset_count(uint8_t value);
void device_params_set_interlocking_state(uint8_t value);

#endif /* DEVICE_CONFIG_DEVICE_PARAMS_NV_H_ */
