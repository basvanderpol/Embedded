/* ******************** Workshop 1 -- Exercise 2 **************************/
#include <stdio.h> // standard C definitions
#include "MCB2300 evaluationboard.h" // hardware related functions

typedef int bool;
#define TRUE 1
#define FALSE 0

bool alarm = FALSE;
int counter = 0;
int LEDvalue = 0x00;
int i;

void delay_temp(void) {
	for(i = 0; i < 20000; i++) { // delay for the buzzer
	
		
	}
}


int main(void) {
 initEvaluationBoard();
 while(1){
	 
	 
switch(alarm)
{


case FALSE: //no alarm (rest phase)//
	LEDvalue=0x00;      
	LEDS=LEDvalue;

if (!INT0) alarm = TRUE; //SIMPLIFY

//	lcd_clear();
//	lcd_setcursor(0,0);
//	lcd_print("no alarm");
     
	//cancel alarm, buzzer
      

      
break;

case TRUE://alarm phase //
	LEDvalue=0xFF;    //TODO: make this blink (use for loop)     
	LEDS=LEDvalue;

if (!INT0) alarm = FALSE;


//	lcd_clear();
//	lcd_setcursor(0,0);
//	lcd_print("s.o.s. alarm");
	

//	 delay_temp();
	//	FIO0SET |= (1<<26);
//	 delay_temp();
//		FIO0CLR |= (1<<26);
	
// TODO: EXIT upon interrupt
	//sound alarm, buzzer
 
break;

}
}
}


