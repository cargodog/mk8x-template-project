#ifndef _PINMUX_CFG_H_
#define _PINMUX_CFG_H_

#include "pinmux.h"
#include "fsl_port.h"

/*
 * Default pinmux configuration
 */
const PinConfig_t defaultPinCfgs[] = {
    [PIN_STATUS_LED] = { 
        .port = PORTC,
        .pin = 12U,
        .cfg = {
            .slewRate               = kPORT_SlowSlewRate,
            .driveStrength          = kPORT_HighDriveStrength,
            .mux                    = kPORT_MuxAsGpio,
        }
    },
    [PIN_DBG_UART_RX] = { 
        .port = PORTB,
        .pin = 16U,
        .cfg = {
            .pullSelect             = kPORT_PullDown,
            .driveStrength          = kPORT_HighDriveStrength,
            .mux                    = kPORT_MuxAlt3,
        }
    },
    [PIN_DBG_UART_TX] = { 
        .port = PORTB,
        .pin = 17U,
        .cfg = {
            .driveStrength          = kPORT_HighDriveStrength,
            .mux                    = kPORT_MuxAlt3,
        }
    },
};
_Static_assert(sizeof(defaultPinCfgs) / sizeof(defaultPinCfgs[0]) >= MAX_NUM_PINS,
                "Missing pin config for one or more pin IDs!");
_Static_assert(sizeof(defaultPinCfgs) / sizeof(defaultPinCfgs[0]) <= MAX_NUM_PINS,
                "Number of pin configs exceeds number of pin IDs!");


#endif /* _PINMUX_CFG_H_ */
