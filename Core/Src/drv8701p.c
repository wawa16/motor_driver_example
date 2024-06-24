/*
 * Copyright (c) 2024 Dometic
 * All rights reserved.
 *
 * Description: DRV8701P API source file
 * Author: Waleed Uddin
*/

#include "drv8701p.h"

// Initialized once, usable by this module only
static uint16_t currentPWMValue = 0;
static uint16_t targetPWMValue = 0;
uint16_t slewRate_ = 0;

void drv8701p_init(void) {
    // Sets to the required slew rate of 1% per ms
    set_slew_rate(DEFAULT_SLEW_RATE);

    // Default initialized state
    set_mode(COAST);
}

void drv8701p_set_command(uint16_t target) {
    // Must cap the target to maximum allowed PWM value
    targetPWMValue = (target > PWM_MAX) ? PWM_MAX : target;
}

void set_slew_rate(uint16_t slewRate) {
    slewRate_ = slewRate;
}

void set_mode(driver_mode mode) {
    // Reference: Table 2 on page 14 of drv8701p datasheet
    switch (mode)
    {
        case SLEEP:
            hal_aio_set_output(HAL_AIO_nSLEEP, 0);
            break;
        case COAST:
            hal_aio_set_output(HAL_AIO_nSLEEP, 1);
            hal_aio_set_output(HAL_AIO_IN1, 0);
            hal_aio_set_output(HAL_AIO_IN2, 0);
            break;
        case BRAKE:
            hal_aio_set_output(HAL_AIO_nSLEEP, 1);
            hal_aio_set_output(HAL_AIO_IN1, 1);
            hal_aio_set_output(HAL_AIO_IN2, 1);
            break;
        case LOWSIDE_SLOW_DECAY:
            hal_aio_set_output(HAL_AIO_nSLEEP, 1);
            hal_aio_set_output(HAL_AIO_IN1, 1);
            hal_aio_set_output(HAL_AIO_IN2, 1);
            break;
        default:
            break;
    }
}

void move(direction dir, uint16_t value) {
    if (dir == FORWARD) {
        // Enable forward motion
        hal_aio_set_output(HAL_AIO_nSLEEP, 1);
        hal_aio_set_output(HAL_AIO_IN1, value);
        hal_aio_set_output(HAL_AIO_IN2, 0);
    }
    else {
        // Enable reverse motion
        hal_aio_set_output(HAL_AIO_nSLEEP, 1);
        hal_aio_set_output(HAL_AIO_IN1, 0);
        hal_aio_set_output(HAL_AIO_IN2, value);
    }
}

void drv8701p_elapse_1ms(void) {
    if (currentPWMValue < targetPWMValue) {
        currentPWMValue += slewRate_; // increment the pwm value by slew rate
        currentPWMValue = (currentPWMValue > targetPWMValue) ? targetPWMValue : currentPWMValue;  // cap it to target
    }
    else if (currentPWMValue > targetPWMValue) {  // slew rate must also apply if pwm decreases
        currentPWMValue -= slewRate_;
        currentPWMValue = (currentPWMValue < targetPWMValue) ? targetPWMValue : currentPWMValue;  // cap it to target
    }

    if (targetPWMValue == 0) {
        // Apply brake if target command is zero
        set_mode(BRAKE);
    }
    else if (currentPWMValue > 0) {
        // Assume a forward motion
        move(FORWARD, currentPWMValue);
    }
}

void drv8701p_apply_slow_decay(void) {
    if (currentPWMValue > 0 && currentPWMValue < PWM_MAX) {
        set_mode(LOWSIDE_SLOW_DECAY);
    }
}
