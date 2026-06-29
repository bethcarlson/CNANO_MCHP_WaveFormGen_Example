#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include "Driver_GPIO.h"

/* LED0 = PA19 */
#define LED0   ARM_GPIO_PIN_PB19
#define LED_ON     1U
#define LED_OFF    0U

/* SW0 = PB03 (active low) */
#define SW0    ARM_GPIO_PIN_PB03

/* Default USART0 baud rate */
#define USART0_DEFAULT_BAUD_RATE   115200U

#endif
