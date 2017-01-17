/*
 * L1.c
 *
 *  Created on: Dec 31, 2016
 *      Author: Vishal Patil
 */
#include<msp430.h>
#include "Led.h"
extern LED Red,Green;
void mConfigLedBlink (LED* this,unsigned int OnTime,unsigned int OffTime,unsigned int Cycles)
{
	this->OnTime = OnTime;
	this->OffTime = OffTime;
	this->Cycles=Cycles;
	this->State =OFF;
}
void ConfigRedLedPort (void)
{
	P1DIR |= BIT0;
	P1OUT &= ~(BIT0);   //Turn Off LEd
}
void TickCallBackRed (void)
{

    if(Red.Enable == ENABLE)
    {
     Red.Ticks++;
     if(Red.State == ON)
     {
     	if(Red.Ticks == Red.OnTime)
    	{
    		RED_OFF;   //Turn Off LEd
    		Red.Ticks =0;
    		Red.State =OFF;
    		if (Red.Cycles != 0) // Continuous Sequence
    		{
    			Red.Cycles--;
    			if(Red.Cycles == 0)  // Required Number of cycles complete Now turn off The led
    			{
    				Red.Enable = DISABLE;
    			}
    		}
    	}
     }
     if(Red.State ==OFF)
     {
    	if(Red.Ticks == Red.OffTime)
    	{
    		RED_ON;
    		Red.Ticks =0;
    		Red.State = ON;
    	}
      }
    }else   // If LED is not Enabled then turn it off
    {
    	RED_OFF;   //Turn Off LEd

    }

}

void TickCallBackGreen (void)
{
	if(Green.Enable == ENABLE)
	{
     Green.Ticks++;
     if(Green.State == ON)
     {
    	if(Green.Ticks == Green.OnTime)
    	{
    		GREEN_OFF;
    		Green.Ticks =0;
    		Green.State =OFF;
    		if (Green.Cycles != 0) // Continuous Sequence
    		    		{
    		    			Green.Cycles--;
    		    			if(Green.Cycles == 0)  // Required Number of cycles complete Now turn off The led
    		    			{
    		    				Green.Enable = DISABLE;
    		    			}
    		    		}
    	}
     }
     if(Green.State ==OFF)
     {
    	if(Green.Ticks == Green.OffTime)
    	{
    		GREEN_ON;
    		Green.Ticks =0;
    		Green.State = ON;
    	}
     }
	}else
	{
		GREEN_OFF; // Else turn off LED.
	}

}

void ConfigGreenLedPort (void)
{
	P1DIR |= BIT6;
	P1OUT &= ~(BIT6);
}

void Start(LED* this){
	this->Enable= ENABLE;
}
void Stop(LED* this){
	this->Enable= DISABLE;
}
