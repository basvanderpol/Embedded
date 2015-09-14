#ifndef _evaluationboard
#define _evaluationboard
#include <LPC23xx.H> // LPC23xx definitions
#include "LCD.h"
#define LEDS FIO2PIN0 // alternative (comprehensive) definition of FIOPIN0
#define INT0 (FIO2PIN1 & 0x04) // int0 is connected to P2.10 (bit 3 of FIO2PIN1)
void initEvaluationBoard(void); // function prototype
#endif
