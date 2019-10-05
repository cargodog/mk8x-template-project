#include "board.h"
#include "pinmux.h"
#include "pinmux_cfg.h"
#include "gpio_cfg.h"
#include "clock_config.h"
#include "printf_port.h"
#include "fsl_port.h"
#include "fsl_gpio.h"


#define INITIALIZE_GPIO_PIN(id, direction, polarity) \
{\
    assert((id) >= 0 && (id) < (MAX_NUM_PINS));\
    GPIO_PinInit(   get_gpio_base(id),\
                    defaultPinCfgs[(id)].pin,\
                    &(const gpio_pin_config_t) {\
                        .pinDirection   = (direction),\
                        .outputLogic    = (polarity)\
                    } );\
}

static GPIO_Type * get_gpio_base(PinID_t pin)
{
    if (defaultPinCfgs[pin].port == PORTA)
        return GPIOA;
    if (defaultPinCfgs[pin].port == PORTB)
        return GPIOB;
    if (defaultPinCfgs[pin].port == PORTC)
        return GPIOC;
    if (defaultPinCfgs[pin].port == PORTD)
        return GPIOD;
    if (defaultPinCfgs[pin].port == PORTE)
        return GPIOE;
    assert(0);
}

static void initialize_gpios(void)
{
    for(int i = 0; i < sizeof(defaultGPIOCfgs)/sizeof(defaultGPIOCfgs[0]); i++) {
        const GPIOConfig_t * const cfg = &defaultGPIOCfgs[i];
        INITIALIZE_GPIO_PIN(cfg->pin, cfg->direction, cfg->defaultOutput);
    }
}

void board_init(void)
{
    clkcfg_run_default();
    initialize_pinmux();
    initialize_gpios();
    initialize_debug_uart();
}

void board_gpio_set(PinID_t pin)
{
    assert((pin) >= 0 && (pin) < (MAX_NUM_PINS));
    GPIO_PortSet(get_gpio_base(pin), (1U << defaultPinCfgs[pin].pin));
}

void board_gpio_clear(PinID_t pin)
{
    assert((pin) >= 0 && (pin) < (MAX_NUM_PINS));
    GPIO_PortClear(get_gpio_base(pin), (1U << defaultPinCfgs[pin].pin));
}

void board_gpio_toggle(PinID_t pin)
{
    assert((pin) >= 0 && (pin) < (MAX_NUM_PINS));
    GPIO_PortToggle(get_gpio_base(pin), (1U << defaultPinCfgs[pin].pin));
}
