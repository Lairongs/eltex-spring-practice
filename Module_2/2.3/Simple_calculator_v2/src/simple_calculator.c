#include <stdio.h>
#include "simple_calculator.h"

float sum_value(const SimpleCalculator *value)        // Функция сложения
{
    return value->first_value + value->second_value;
}

float sub_value(const SimpleCalculator *value)         // Функция вычитания
{
    return value->first_value - value->second_value;
}
float multiply_value(const SimpleCalculator *value)   // Функция умножения
{
    return value->first_value * value->second_value;
}
float div_value(const SimpleCalculator *value)         // Функция деления
{
    return value->first_value / value->second_value;
}

float (*select(int chioce))(const SimpleCalculator *value)
{
    switch (chioce)
    {
        case 1: return sum_value;
        case 2: return sub_value;
        case 3: return multiply_value;
        case 4: return div_value;
        default: return NULL;
    }
}
