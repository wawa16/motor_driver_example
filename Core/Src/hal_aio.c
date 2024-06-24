#include "hal_aio.h"

void hal_aio_set_output(hal_aio_output_t output, uint16_t pwm) {
    switch (output) {
    case HAL_AIO_nSLEEP:
        // Here will be the board-specific code to enable nSLEEP pin
        break;
    case HAL_AIO_IN1:
        // Here will be the board-specific code to control PWM IN1
        break;
    case HAL_AIO_IN2:
        // Here will be the board-specific code to control PWM IN2
        break;
    }
}