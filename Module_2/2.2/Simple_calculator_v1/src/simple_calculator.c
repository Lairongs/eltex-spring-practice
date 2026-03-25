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

