#include <msp430.h>
#include "switches.h"
#include "statemachine.h"
#include "buzzer.h"
#include "led.h"

char  s_1D, s_2D, s_3D, s_4D, cyc_led_sw, switch_state_changed; /* effectively booleans that indicate whether a switch is on or off */

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  
  //switch_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  //switch_state_changed = 1;
  //led_update();

  s_1D = (p2val & SW1) ? 0 : 1;
  s_2D = (p2val & SW2) ? 0 : 1;
  s_3D = (p2val & SW3) ? 0 : 1;
  s_4D = (p2val & SW4) ? 0 : 1;

  //if a button is on then the the respective stuff will happen
  if(s_1D){
    led_buzzer_controller();
  }
  if(s_2D){
    reset_all();

  }
  if(s_3D){
    cyc_led_sw = 1;

  }
  if(s_4D){
    cyc_led_sw = 0;

  }
  
}
