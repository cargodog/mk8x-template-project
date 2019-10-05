#include "printf_port.h"
#include "printf.h"
#include "fsl_lpuart.h"
#include "fsl_clock.h"

void initialize_debug_uart()
{
    lpuart_config_t config;

    CLOCK_SetLpuartClock(2U);

    LPUART_GetDefaultConfig(&config);
    config.baudRate_Bps = DBG_BAUDRATE;
    config.enableTx     = true;
    config.enableRx     = true;

    LPUART_Init(DBG_LPUART, &config, DBG_LPUART_CLK_FREQ);
}

void _putchar(char character)
{
    return LPUART_WriteBlocking(DBG_LPUART, (unsigned char *)&character, 1);
}
