#include "board.h"
#include "printf.h"
#include "microcli.h"
#include "timer_utils.h"
#include "led_blink.h"


#define CMD_ENTRY(fn, help) {fn, #fn, help}

int help(MicroCLI_t * ctx, const char * args);
int ledOff(MicroCLI_t * ctx, const char * args);
int ledOn(MicroCLI_t * ctx, const char * args);
int startBlink(MicroCLI_t * ctx, const char * args) {blink_enable(); return 0;}
int stopBlink(MicroCLI_t * ctx, const char * args) {blink_disable(); return 0;}

MicroCLI_t dbg;
const MicroCLICmdEntry_t cmdTable[] = {
    CMD_ENTRY(help,             "Print this help message"),
    CMD_ENTRY(ledOff,           "Turn off the LED"),
    CMD_ENTRY(ledOn,            "Turn on the LED"),
    CMD_ENTRY(startBlink,       "Start blinking the LED"),
    CMD_ENTRY(stopBlink,        "Stop blinking the LED"),
};
const MicroCLICfg_t dbgCfg = {
    .bannerText = "\r\n\n\n\nDemo CLI!\r\n\n",
    .promptText = "> ",
    .cmdTable = cmdTable,
    .cmdCount = sizeof(cmdTable)/sizeof(cmdTable[0]),
    .io.printf = printf,
    .io.getchar = board_dbg_uart_getchar_non_blocking,
};


int help(MicroCLI_t * ctx, const char * args)
{
    return microcli_help(&dbg);
}

int ledOff(MicroCLI_t * ctx, const char * args)
{
    board_status_led_off();
    return 0;
}

int ledOn(MicroCLI_t * ctx, const char * args)
{
    board_status_led_on();
    return 0;
}

int main(void)
{
    static const int TICK_PERIOD_MS = 10;
    board_init();

    // Start the CLI
    microcli_init(&dbg, &dbgCfg);
    microcli_banner(&dbg);
    microcli_interpret_string(&dbg, "help", false);

    while(1) {
        // Tick each sub-process
        microcli_interpreter_tick(&dbg);
        blink_tick(TICK_PERIOD_MS);

        // Delay
        delay_ms(TICK_PERIOD_MS);
    }
}