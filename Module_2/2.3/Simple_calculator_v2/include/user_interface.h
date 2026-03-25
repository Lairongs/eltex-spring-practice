#ifndef USER_INTERFACE
#define USER_INTERFACE

#include "simple_calculator.h"

void main_block(void);
void print_main_menu(void);

int input_values(SimpleCalculator *simpleCalculator, float (*operation)(const SimpleCalculator *));

int read_value(float *value);

#endif
