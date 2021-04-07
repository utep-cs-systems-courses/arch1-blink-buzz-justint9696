#include <msp430.h>

#include "led.h"
#include "button.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  if (++blink_count == 250) {
    toggle_led();
    blink_count = 0;
  }
}
