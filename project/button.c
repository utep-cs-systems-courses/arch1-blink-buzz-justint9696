#include <msp430.h>

#include "led.h"
#include "button.h"

#include <stdlib.h>

char button_pressed = 0;

void init_button() {
  // Initialize button for use.
  P1REN |= BUTTON;
  P1IE |= BUTTON;
  P1OUT |= BUTTON;
  P1DIR &= ~BUTTON;
  
  button_handler();
}

static char button_handler() {
  P1IES |= (P1IN & BUTTON);
  P1IES &= (P1IN | ~BUTTON);

  return P1IN;
}

void monitor_button() {
  char p1val = button_handler();

  if ((p1val & BUTTON) == 1 && !button_pressed) {
    toggle_led();
    button_pressed = 1;
  } else if ((p1val & button) == 0) button_pressed = 0; 
}
