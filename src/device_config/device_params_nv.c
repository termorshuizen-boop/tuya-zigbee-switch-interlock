#include <stdbool.h>
#include "device_params_nv.h"
#include "hal/nvm.h"
#include "nvm_items.h"

uint8_t g_multi_press_reset_count = 10;
uint8_t g_interlocking_state = 0;

void device_params_load_from_nv(void) {
    uint8_t          multi_press_reset_count;
    uint8_t          interlocking_state;
    hal_nvm_status_t st;

    st = hal_nvm_read(NV_ITEM_MULTI_PRESS_RESET_COUNT, sizeof(multi_press_reset_count),
                     (uint8_t *)&multi_press_reset_count);
    if (st == HAL_NVM_SUCCESS) {
        g_multi_press_reset_count = multi_press_reset_count;
    }

    // st = hal_nvm_read(NV_ITEM_INTERLOCKING_STATE, sizeof(interlocking_state),
    //                   (uint8_t *)&interlocking_state);
    // if (st == HAL_NVM_SUCCESS) {
    //     g_interlocking_state = interlocking_state;
    // }
}

void device_params_set_multi_press_reset_count(uint8_t value) {
    g_multi_press_reset_count = value;
    hal_nvm_write(NV_ITEM_MULTI_PRESS_RESET_COUNT, sizeof(value),
                  (uint8_t *)&value);
}

void device_params_set_interlocking_state(uint8_t value) {
    g_interlocking_state = value;
    // hal_nvm_write(NV_ITEM_INTERLOCKING_STATE, sizeof(value),
    //               (uint8_t *)&value);
}
