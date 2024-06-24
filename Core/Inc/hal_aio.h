#ifndef HAL_AIO_H
#define HAL_AIO_H

#include <stdint.h>

#define HAL_AIO_PWM_MAX 10000  // corresponds to 100% PWM duty cycle

typedef enum
{
    HAL_AIO_nSLEEP,
    HAL_AIO_IN1,
    HAL_AIO_IN2,
} hal_aio_output_t;

// Assumed to be implemented
void hal_aio_set_output(hal_aio_output_t output, uint16_t pwm);

#endif // HAL_AIO_H