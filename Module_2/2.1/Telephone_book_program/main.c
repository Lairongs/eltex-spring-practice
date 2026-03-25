#include <stdio.h>
#include "user_interface.h"
#include <locale.h>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    TelephoneBook book;
    init_telephonebook(&book);
    load_demo_contacts(&book);
    main_IO_telephoneBook(&book);

    return 0;
}