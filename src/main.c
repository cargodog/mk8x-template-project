#include "board.h"
#include "printf.h"
#include "microcli.h"
#include "fsl_clock.h"


int help(void);
int poke(void);
int startBlinking(void);
int stopBlinking(void);
int ledOff(void);
int ledOn(void);

MicroCLI_t dbg;
const MicroCLICmdEntry_t cmdTable[] = {
    {"help",            help,           "Print this help message"},
    {"ledOff",          ledOff,         "Turn off the LED"},
    {"ledOn",           ledOn,          "Turn on the LED"},
    {"poke",            poke,           "Poke the poor circuit"},
    {"startBlinking",   startBlinking,  "Start blinking the LED"},
    {"stopBlinking",    stopBlinking,   "Stop blinking the LED"},
};
const MicroCLICfg_t dbgCfg = {
    .bannerText = "\r\n\n\n\nDemo CLI!\r\n",
    .promptText = "> ",
    .cmdTable = cmdTable,
    .cmdCount = sizeof(cmdTable)/sizeof(cmdTable[0]),
    .io.printf = printf,
    .io.getchar = board_dbg_uart_getchar_non_blocking,
};
bool blinkEnable = true;


uint32_t ms_to_ticks(uint32_t ms)
{
    uint32_t ticks = CLOCK_GetCoreSysClkFreq();
    return ms * (ticks / 1000);
}

void delay_ms(const uint32_t ms)
{
    static const uint32_t loopOverheadTicks = 19;
    volatile uint32_t sysTickCounter = ms_to_ticks(ms);
    while (sysTickCounter > loopOverheadTicks) {
        sysTickCounter -= loopOverheadTicks;
    }
}

int help(void)
{
    return microcli_help(&dbg);
}

int poke(void)
{
    microcli_log(&dbg, "ouch!\n\r");
    return 0;
}


int startBlinking(void)
{
    blinkEnable = true;
    return 0;
}

int stopBlinking(void)
{
    blinkEnable = false;
    return 0;
}

int ledOff(void)
{
    board_status_led_off();
    return 0;
}

int ledOn(void)
{
    board_status_led_on();
    return 0;
}

void blink_tick(int ms)
{
    static const int BLINK_PERIOD_MS = 1000;
    static int msCounter = 0;

    assert(ms > 0);

    msCounter += ms;

    if(msCounter > BLINK_PERIOD_MS && blinkEnable == true) {
        board_status_led_toggle();
        msCounter = 0;
    }
}

int main(void)
{
    static const int TICK_PERIOD_MS = 10;
    board_init();

    microcli_init(&dbg, &dbgCfg);
    microcli_banner(&dbg);
    while(1) {
        delay_ms(TICK_PERIOD_MS);
        microcli_interpreter_tick(&dbg);
        blink_tick(TICK_PERIOD_MS);
    }
}