
#ifndef _LED_
#define _LED_

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

extern char led_timer;
extern char led_state;

void init_led();

void led_red();

void led_green();

void led_all();

void led_off();

void toggle_led();

void toggle_timer();

char get_state();

char get_timer();

#endif
