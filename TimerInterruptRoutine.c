/*
 * TimerInterruptRoutine.c
 *
 *  Created on: Dec 31, 2016
 *      Author: VIshal Patil
 */


// Timer0_A0 Interrupt Service  Routine:
/******************************************************************************/
#include<msp430.h>
#include "Led.h"
extern LED Red,Green;
#pragma vector=TIMER0_A0_VECTOR
__interrupt void ISR_Timer0_A0(void)
{

	 Red.TickCallback();
	 Green.TickCallback();

}
