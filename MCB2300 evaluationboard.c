#include "MCB2300 evaluationboard.h"
void initEvaluationBoard(void) {
PINSEL10 = 0; // Disable ETM interface, enable LEDs
FIO2DIR0 = 0xFF;
SCS |= (1<<0);
lcd_init();
lcd_clear();
}
