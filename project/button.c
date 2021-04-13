#include <msp430.h>

#include "led.h"
#include "button.h"
#include "buzzer.h"

/* 
 * Program contains code to detect button presses on msp430. Pressing button stops or resumes
 * led cycle.
 *
 */

char button_pressed = 0;
char button_state_changed = 0;

void init_button() {
  P2REN |= BUTTONS;
  P2IE |= BUTTONS;
  P2OUT |= BUTTONS;
  P2DIR &= ~BUTTONS;

  toggle_state();
  button_handler();
}

static char button_handler() {
  char p2val = P2IN;
  P2IES |= (P2IN & BUTTONS);
  P2IES &= (P2IN | ~BUTTONS);

  return p2val;
}

void button_interrupt_handler() {
  char p2val = button_handler();
  button_pressed = (p2val & BTN1) ? 0 : 1;
  if (button_pressed) {
    set_buzzer(1000);
    if (!button_state_changed) {
      toggle_timer();
      button_state_changed = 1;
    }
  } else {
    if (button_state_changed) {
      set_buzzer(0);
      button_state_changed = 0;
    }
  }
}
