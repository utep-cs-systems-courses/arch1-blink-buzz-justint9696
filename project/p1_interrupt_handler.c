#include <msp430.h>

#include "button.h"

void __interrupt_vec(PORT1_VECTOR) Port1() {
  if (P1IFG & BUTTON) {
    P1IFG &= ~BUTTON;
    monitor_button();
  }
}
