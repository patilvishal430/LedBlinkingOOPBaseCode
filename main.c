#include <msp430.h>
#include "Led.h"

LED Red,Green;

unsigned char i;
int main(void) {

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

     Red.ConfigLedBlink = mConfigLedBlink;   //Constructor
     Red.ConfigLedPort  = ConfigRedLedPort;  //LED Specific
     Red.TickCallback = TickCallBackRed;
     Red.Start = Start;
     Red.Stop = Stop;

     Green.ConfigLedBlink =mConfigLedBlink;
     Green.ConfigLedPort = ConfigGreenLedPort;
     Green.TickCallback = TickCallBackGreen;
     Green.Start =Start;
     Green.Stop = Stop;


     Red.ConfigLedBlink(&Red,500,500,20);
     Red.ConfigLedPort();
     Red.Start(&Red);

     Green.ConfigLedBlink(&Green,1000,1000,0);
     Green.ConfigLedPort();
     Green.Start(&Green);
    // CallBack1 = Red.TickCallback;
     //CallBack2 = Green.TickCallback;

   //Start timer  for time base.
     TA0CCR0 = 1000;
              TA0CTL = TASSEL_2 + MC_1 + TACLR;
              TA0CCTL0 &= ~CCIFG;
              TA0CCTL0 = CCIE;
              __bis_SR_register(GIE);
              __no_operation();
              while(1);

	
	//return 0;
}







