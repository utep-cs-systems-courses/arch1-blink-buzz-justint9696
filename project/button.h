#ifndef _BUTTON_
#define _BUTTON_

#define BTN1 BIT0
#define BTN2 BIT1
#define BTN3 BIT2
#define BTN4 BIT3
#define BUTTONS (BTN1 | BTN2 | BTN3 | BTN4)

extern char button_pressed;
extern char button_state_changed;

void init_button();

static char button_handler();

void button_interrupt_handler();

#endif
