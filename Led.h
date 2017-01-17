/*
 *  Led.h
 *
 *  Created on: Dec 31, 2016
 *  Author: Vishal Patil ,
 */

#ifndef LED_H_
#define LED_H_

/* Definition */

#define ON 1
#define OFF 0
#define ENABLE 1
#define DISABLE 0
#define RED_OFF   P1OUT &= ~(BIT0)        // Red LED is on Port1 and at Pin 0
#define RED_ON    P1OUT |= BIT0           //
#define GREEN_OFF  P1OUT &= ~(BIT6)       // Green LED is at Port 1 and at pin 6
#define GREEN_ON  P1OUT |= BIT6

typedef struct Led LED;

/* This Structure defines LED class using which instance of LED objects can be created.
 * This LED class have Attributes(Variables) = OnTime, OffTime,Cycles,Sate,Ticks
 * and methods which operate on LED object are
 * ConfigLedPort      // Configures port for LED (Output pin selection and configuration
 * ConfigLedBlink     // Configures and Initializes each LED object instance with provided attributes
 * Start
 * Stop
 * and TickCallback (In which actual LED blinking done)
 *
 */
struct Led{
	unsigned int OnTime;
	unsigned int OffTime;
	unsigned int Cycles;
	unsigned int Ticks;
	unsigned char  State;
	unsigned char  Enable;

	void (*ConfigLedPort)(void);
	void (*ConfigLedBlink)(LED*,unsigned int,unsigned int,unsigned int);
	void (*Start)(LED*);
	void (*Stop)(LED*);
	void (*TickCallback)(void);
};

void mConfigLedBlink (LED*,unsigned int OnTime,unsigned int OffTime,unsigned int Cycles);//Configure LED
void ConfigRedLedPort (void);       // Configure LED port on Which LED is connected  Makes that pin Output
void TickCallBackRed (void);
void ConfigGreenLedPort(void);
inline void TickCallBackGreen (void);
void Start(LED*);
void Stop(LED*);



#endif /* LED_H_ */
