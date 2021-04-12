#ifndef switches_included
#define switches_included

#define SW1 BIT0		/* all switches on the green board */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)		/* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char s_1D, s_2D, s_3D, s_4D, cyc_led_sw, switch_state_changed; /* effectively boolean */

#endif // included
