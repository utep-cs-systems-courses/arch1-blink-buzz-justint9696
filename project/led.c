#include <msp430.h>

#include "led.h"

/*
 * Program contains states to turn red and green leds on and off. This is done by changing the 
 * bits of the port attached to the leds on the board. These bits are stored in various addresses.
 */

void init_led() {
  // Sets P1DIR to 'output' mode by setting bit0 and bit6 to 1 by - 0 | 1 = 1
  P1DIR |= LEDS;
}

void led_red() {
  P1OUT &= (0xff ^ LEDS) | LED_RED;
  P1OUT |= LED_RED;
}

void led_green() {
  P1OUT &= (0xff ^ LEDS) | LED_GREEN;
  P1OUT |= LED_GREEN;
}

void led_all() {
  P1OUT &= (0xff ^ LEDS) | LEDS;
  P1OUT |= LEDS;
}

void led_off() {
  P1OUT &= ~1;
}

char toggle_led() {
  static char led_state = 0;
  switch (led_state) {
  case 0:
    led_state = 1;
    led_red();
    break;
  case 1:
    led_state = 2;
    led_green();
    break;
  case 2:
    led_state = 3;
    led_all();
    break;
  case 3:
    led_state = 0;
    led_off();
    break;
  default:
    led_state = 1;
    led_red();
    break;
  }
  return led_state;
}
