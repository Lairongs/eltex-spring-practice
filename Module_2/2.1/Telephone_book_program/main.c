#include <stdio.h>
#include "user_interface.h"
#include <locale.h>
#include <windows.h>

int main() {
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);
    // setlocale(LC_ALL, "Russian");

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".UTF-8");

    TelephoneBook book;
    init_telephonebook(&book);
    load_demo_contacts(&book);
    main_IO_telephoneBook(&book);

    return 0;
}