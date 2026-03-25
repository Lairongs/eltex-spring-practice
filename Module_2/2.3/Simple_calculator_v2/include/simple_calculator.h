#ifndef SIMPLE_CALCULATOR
#define SIMPLE_CALCULATOR

typedef struct
{
    float first_value;
    float second_value;
}SimpleCalculator; 


float sum_value(const SimpleCalculator *value);         // Функция сложения
float sub_value(const SimpleCalculator *value);         // Функция вычитания
float multiply_value(const SimpleCalculator *value);    // Функция умножения
float div_value(const SimpleCalculator *value);         // Функция деления

float (*select(int chioce))(const SimpleCalculator *value);


#endif