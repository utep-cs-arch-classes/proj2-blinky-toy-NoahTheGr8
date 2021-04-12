#include <msp430.h>
#include "statemachine.h"
#include "led.h"
#include "buzzer.h"

static char state = 0;

//this will control the sound along with the leds when the button is pressed
void led_buzzer_controller(){

  switch(state){

  case 0:
    
    buzzer_set_period(100); red_on = 0; green_on = 0;
    state = 1;
    break;


  case 1:

    buzzer_set_period(200); red_on = 1; green_on = 0;
    state = 2;
    break;


  case 2:

    buzzer_set_period(300); red_on = 0; green_on = 1;
    state = 3;
    break;

  case 3:

    buzzer_set_period(500); red_on = 1; green_on = 1;
    state = 0;

    break;
  }

  //update the lights after each turn the lights get when the light up
  led_changed = 1; 
  led_update();

}

//resets the buzzer and leds 
void reset_all(){

  buzzer_set_period(0);
  count = 0;
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();

}


static char light_state;

//when a button is pressed then the lights will cycle | both on, only red on, only green on, both off
void cycle_lights(){

  switch(light_state){

  case 0:

    red_on = 0;
    green_on = 0;
    light_state = 1;
    break;
    
  case 1:
    
    red_on = 0;
    green_on = 1;
    light_state = 2;
    break;
    
  case 2:

    red_on = 1;
    green_on = 0;
    light_state = 3;
    break;

  case 3:
    red_on = 1;
    green_on = 1;
    light_state = 0;
    break;

  }

  led_changed = 1;
  led_update();

}//cycle_lights
