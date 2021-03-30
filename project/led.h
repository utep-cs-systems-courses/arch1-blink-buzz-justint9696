#ifndef _LED_
#define _LED_

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

extern char led;

void led_red();

void led_green();

void led_all();

void led_off();

char toggle_led();

#endif
