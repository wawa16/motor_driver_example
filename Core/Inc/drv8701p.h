/*
 * Copyright (c) 2024 Dometic
 * All rights reserved.
 *
 * Description: DRV8701P API header file
 * Author: Waleed Uddin
*/

#ifndef DRV8701P_H
#define DRV8701P_H

#include "hal_aio.h"

#define PWM_MAX 10000 // 10000 is the max duty cycle
#define DEFAULT_SLEW_RATE 100 // 1% per millisecond increment

typedef enum
{
    FORWARD,
    REVERSE,
} direction;

typedef enum
{
    SLEEP = 2,  // H-bridge disabled
    COAST = 3,  // H-bridge disabled
    BRAKE = 4,
    LOWSIDE_SLOW_DECAY = 5,
} driver_mode;

void drv8701p_init(void);

/*
 * Sets a new PWM target command
 *
 * @param target: The desired PWM duty cycle 0 - PWM_MAX
 */
void drv8701p_set_command(uint16_t target);

/*
 * Called by an application at 1kHz, high-level function to process PWM commands with desired slew rate
 *
 */
void drv8701p_elapse_1ms(void);

/*
 * Sets driver mode
 *
 * @param driver_mode: An enum with various driver states
 */
void set_mode(driver_mode mode);

/*
 * Moves the motor in either forward or reverse, given direction and the pwm command
 *
 * @param dir: A direction enum either forward or reverse
 * @param value: PWM value
 */
void move(direction dir, uint16_t value);

/*
 * Helper function to set the slew rate
 *
 * @param slewRate: desired slew rate to be set
 */
void set_slew_rate(uint16_t slewRate);

/*
 * Called by an application to apply slow decay during off PWM portion
 *
 */
void drv8701p_apply_slow_decay(void);

extern uint16_t slewRate_;

#endif // DRV8701P_H
