/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "pico/time.h"

int main() {
    uint i = 0;
    for (i = 0; i < 8; i++) {
        gpio_init(i);
        gpio_set_dir(i, GPIO_OUT);
    }
    while (true) {
        for (i = 0; i < 8; i++) {
            gpio_put(i, 1);
            sleep_ms(50);
        }
        for (i = 0; i < 8; i++) {
            gpio_put(i, 0);
            sleep_ms(50);
        }
    }
}
