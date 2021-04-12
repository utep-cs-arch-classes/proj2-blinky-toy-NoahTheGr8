#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "statemachine.h"

/*
This is a timer as well as an indicator to when lights should switch states
*/

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if ((++blink_count == 125) && (cyc_led_sw==1) ) {
    cycle_lights();
    blink_count = 0;
  }
  else if(cyc_led_sw==0){
    red_on = 0;
    green_on = 0;
    led_changed = 1;
    led_update();
  }
  
}
