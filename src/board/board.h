#ifndef _BOARD_H_
#define _BOARD_H_

#include "pinmux.h"

#define BOARD_DEBUG_UART_BAUDRATE 115200

// initialization
void board_init(void);

// Generic GPIO control
void board_gpio_set(PinID_t pin);
void board_gpio_clear(PinID_t pin);
void board_gpio_toggle(PinID_t pin);

// Status LED control
static inline void board_status_led_on(void) {board_gpio_set(PIN_STATUS_LED);}
static inline void board_status_led_off(void) {board_gpio_clear(PIN_STATUS_LED);}
static inline void board_status_led_toggle(void) {board_gpio_toggle(PIN_STATUS_LED);}


#endif /* _BOARD_H_ */