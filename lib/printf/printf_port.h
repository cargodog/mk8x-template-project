#ifndef _PRINTF_PORT_H_
#define _PRINTF_PORT_H_

#define DBG_LPUART LPUART0
#define DBG_BAUDRATE 115200
#define DBG_LPUART_CLK_FREQ CLOCK_GetFreq(kCLOCK_Osc0ErClk)


void initialize_debug_uart();

#endif /* _PRINTF_PORT_H_ */