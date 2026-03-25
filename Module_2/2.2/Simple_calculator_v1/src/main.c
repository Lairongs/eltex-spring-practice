#include <stdio.h>
#include "user_interface.h"
#include <locale.h>
#include <windows.h>

int main() {
    
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".UTF-8");

    main_block();
    return 0;
}