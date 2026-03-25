#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "simple_calculator.h"


int read_value(float *value)
{
    char buffer[100];
    char *endptr;
    float temp;
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0;
    }

    temp = strtof(buffer, &endptr);

    if (buffer == endptr) {
        return 0;
    }

    while (isspace((unsigned char)*endptr)) {
        endptr++;
    }

    if (*endptr != '\0') {
        return 0;
    }

    *value = temp;

    return 1;
}


void print_main_menu(void)
{
    printf("============================ Меню калькулятора ============================\n\n");

    printf(">> Выберите из списка операцию которую хотите выполнить\n\n");

    printf("1. Сложение\n");
    printf("2. Вычитание\n");
    printf("3. Умножение\n");
    printf("4. Деление\n");
    printf("0. Выход\n\n");
    printf("Выберите необходимый пункт из списка (Только число!): ");
}


int input_values(SimpleCalculator *simpleCalculator, const int selected_value)
{
    if(simpleCalculator == NULL || selected_value < 0 || selected_value > 4 ) return 0;

    float temp_first_value;
    float temp_second_value;

    printf("\nВведите первое число: ");
    if(!read_value(&temp_first_value)) 
    {
        printf("Ошибка ввода. Вы ввели некорректное число! \n");
        return 0;
    }

    printf("Введите второе число: ");
    if(!read_value(&temp_second_value)) 
    {
        printf("Ошибка ввода. Вы ввели некорректное число! \n");
        return 0;
    }    

    if(selected_value == 4 && (temp_first_value == 0 || temp_second_value == 0))
    {
        printf("\nДелить на ноль запрещено !!! \n");
        return 0;
    }

    // Сохраняем значение в структуру
    simpleCalculator->first_value = temp_first_value;
    simpleCalculator->second_value = temp_second_value;
    return 1;
}


void main_block(void)
{ 
    SimpleCalculator value;
    value.first_value = 0;
    value.second_value = 0;
    
    int select_index;

    while(1)
    {
        print_main_menu();
        if (scanf("%d", &select_index) != 1)
        {
            printf("Ошибка ввода. Нужно ввести число.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (select_index)
        {
            case 0:
                return;
            case 1:
            {
                if(!input_values(&value, select_index))
                {
                    printf("Ошибка в операции!!! Повторите операцию еще раз! \n\n");
                    continue;
                }
                printf("\n------------------------------------------------\n\n");
                printf("Результат суммы: %g\n\n", sum_value(&value));
                printf("------------------------------------------------\n\n\n");
                break;
            }    
                
            case 2:
            {
                if(!input_values(&value,select_index))
                {
                    printf("Ошибка в операции!!! Повторите операцию еще раз! \n\n");
                    continue;
                }
                printf("\n------------------------------------------------\n\n");
                printf("Результат разности: %g\n", sub_value(&value));
                printf("------------------------------------------------\n\n\n");
                break;     
            }                
            case 3:
            {
                if(!input_values(&value,select_index))
                {
                    printf("Ошибка в операции!!! Повторите операцию еще раз! \n\n");
                    continue;
                }
                printf("\n------------------------------------------------\n\n");
                printf("Результат умножения: %g\n\n", multiply_value(&value));
                printf("------------------------------------------------\n\n\n");
                break;      
            }
            case 4:
            {
                if(!input_values(&value,select_index))
                {
                    printf("Ошибка в операции!!! Повторите операцию еще раз! \n\n");
                    continue;
                }
                printf("\n------------------------------------------------\n\n");
                printf("Результат деления: %g\n\n", div_value(&value));
                printf("------------------------------------------------\n\n\n");
                break;      
            }
            default:
                printf("Неверный пункт меню.\n");
                break;
        }
    }
}
