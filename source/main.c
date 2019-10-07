/*	Author: xwalt001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;	
	unsigned char cntavail = 0x00;	
	unsigned char full = 0x00;

	while(1) {
		// 1) Read input
		tmpA = PINA & 0x0F;	
		// 2) Perform computation
	
		//set full to false and number of avail spaces to 4	
		full = 0;	
		cntavail = 0x04;
	
		//count number of ones in binary number	
		unsigned char i = 0x00;
		
		for(i = 0; i < 4; i++){
			if(tmpA & 0x01){
				cntavail--;	
			}		
			
			tmpA = tmpA >> 1;
		}
	
		//if all spaces have car full = 1	
		if ( cntavail == 0){
			full = 1;			
		}	
	// 3) Write output
	
		if (full){
			tmpC = ( tmpC | 0x80 );	
		}	
		else{
			tmpC = ( tmpC & 0x7F );
		}
		tmpC = ( tmpC & 0xF0) | ( cntavail & 0x0F) ;

		PORTC = tmpC;
	
	}
	return 0;
}
