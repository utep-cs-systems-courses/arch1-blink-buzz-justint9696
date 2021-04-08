#include <msp430.h>

#include "led.h"
#include "button.h"

/* 
 * Program contains code to detect button presses on msp430. Pressing button stops or resumes
 * led cycle.
 *
 */

void init_button() {
  P1REN |= BUTTON;
  P1IE |= BUTTON;
  P1OUT |= BUTTON;
  P1DIR &= ~BUTTON;

  toggle_led();
  button_handler();
}

static char button_handler() {
  char p1val = P1IN;
  P1IES |= (P1IN & BUTTON);
  P1IES &= (P1IN | ~BUTTON);

  return p1val;
}

void monitor_button() {
  char p1val = button_handler();
  static char button_pressed = 0;
  if (p1val & BUTTON) {
    if (!button_pressed) {
      toggle_timer();
      button_pressed = 1;
    }
  } else
    button_pressed = 0;
}
