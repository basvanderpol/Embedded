/*
Question 2
Which registers are required to have the INT0 button interrupt protocol?
Adress, Priority, Enable, EXTINT, EXTMODE, EXTPOLAR, PINSEL4 (20) . (PIN 14 for enable)

__irq void EINT0_ISR(void){
//INTERRUPT
VicVectAddr = 0; //ACKNOWLEDGE
}

VICVectAddr14 = unsigned long EINT0_ISR;
VICVectPriority14 = 14;
VICIntEnable = (1<<14);
EXTINT |= 0x01;
EXTMODE0 |= 0x01;
PINSEL4 |=(1<<20);

Question 3

VICVectAddr4 = unsigned long TIMER0_ISR;
VICVectPriority4 = 15;
VICIntEnable = (1<<4);
PCLKSEL0 |= (1<<2)
PCLKSEL0 |= (1<<3)

PINSEL4 |=(1<<20);


*/
#include <stdio.h> // standard C definitions
#include "MCB2300 evaluationboard.h" // hardware related functions
/*
int x;
struct _Time {
unsigned char hours;
unsigned char minutes;
unsigned char seconds;
unsigned short onehundreds; 
};

typedef struct _Time Time;
Time t;

__irq void TIMER0_ISR(void){
	x++;
	T0IR = 1; // Clear interrupt flag
  VICVectAddr = 0; 
}
void increaseTime (Time*t){
	
};

void init_T1(void) {
 T0MR0 = 11999999; // 12Mcylces - 1
 T0MCR = 3; // Enable interrupt, reset on match register 0
 T0TCR = 1; // Enable timer1
 VICVectAddr4 = (unsigned long)TIMER0_ISR; // Set interrupt vector
 VICVectPriority4 = 15; // Set to priority 10 (arbitrary value)
 VICIntEnable = (1 << 4); // Enable Ttimer1 Interrupt
 
	PCLKSEL0 |= (1<<2);
	PCLKSEL0 |= (1<<3);
}
*/
struct _Time {
unsigned char h;
unsigned char m;
unsigned char s;
unsigned short hs; 
};

struct _Time current;

char textbuf[17];
/************** interrupt service routine timer1 ******************/
__irq void T0_ISR (void) {
 current.hs++; // Increase x
 T0IR = 1; // Clear interrupt flag
 VICVectAddr = 0; // Update interrupt priority hardware
}
/******************** initializing timer1 ************************/
void init_T0(void) {
	// By default the timer is set /4 prescale and I'm okay with it
 T0MR0 = 119999; // 12Mcylces - 1
 T0MCR = 3; // Enable interrupt, reset on match register 0
 T0TCR = 1; // Enable timer1
 VICVectAddr4 = (unsigned long)T0_ISR; // Set interrupt vector
 VICVectPriority4 = 15; // Set to priority 15 (arbitrary value)
 VICIntEnable = (1 << 4); // Enable Ttimer1 Interrupt
}

void update_currentT(){
	if(current.hs>98){
		current.hs=0;
		current.s++;
	}
	if(current.s>59){
		current.s=0;
		current.m++;
	}
	if(current.m>59){
		current.m=0;
		current.h++;
	}
	set_cursor(0,0);
	sprintf(textbuf,"%02d:%02d:%02d:%02d",current.h,current.m,current.s,current.hs);
	lcd_print(textbuf);
}
int main(void) {
 init_T0();
 initEvaluationBoard();
 while(1){
	//DETERMINE HOW LONG E
	 update_currentT();
		}
}



