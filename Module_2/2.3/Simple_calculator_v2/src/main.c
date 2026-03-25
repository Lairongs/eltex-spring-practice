#include <stdio.h>
#include "user_interface.h"
#include <locale.h>


int main() {
    
    setlocale(LC_ALL, ".UTF-8");

    main_block();
    return 0;
}