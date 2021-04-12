#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

int main(void){

  configureClocks(); //set up master oscillator and master clocks
  enableWDTInterrupts();//Enable periodic interruption according to timer ONLY - for the LED's or buzzer
  led_init(); //sets or engages the LED's
  buzzer_init(); //sets up the little speaker for us
  buzzer_set_period(0); //resets the buzzer and tells it to set the Hz to 0 or OFF
  switch_init(); //sets or engages switches or buttons on the green board
  or_sr(0x18); //? 


}//main
