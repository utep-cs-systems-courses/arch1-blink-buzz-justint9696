#include <msp430.h>

#include "led.h"

char led = 3;

void led_red() {
  led = 1; 

  P1OUT &= (0xFF ^ LEDS) | LED_RED; //
  P1OUT |= LED_RED;
}

void led_green() {
  led = 2;

  P1OUT &= (0xFF ^ LEDS) | LED_GREEN;
  P1OUT |= LED_GREEN;
}

void led_all() {
  led = 3;

  P1OUT &= (0xFF ^ LEDS) | LEDS;
  P1OUT |= LEDS;
}

void led_off() {
  led = 0;

  P1OUT = 0;
}

char toggle_led() {
  P1DIR |= LEDS;
  
  switch (led) {
  case 0:
    led_red();
    break;
  case 1:
    led_green();
    break;
  case 2:
    led_all();
    break;
  case 3:
    led_off();
    break;
  default:
    led_red();
    break;
  }
  return led;
}
