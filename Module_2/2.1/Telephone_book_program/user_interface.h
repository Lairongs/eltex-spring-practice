#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "telephonebook.h"

void main_IO_telephoneBook(TelephoneBook *book);

void print_main_menu(void);                    // Реализовано
void print_add_contact_menu(void);             // Реализовано 
void print_edit_contact_menu(void);            // Реализовано 

void print_contact_telephones_menu(void);      // Реализовано 
void print_contact_emails_menu(void);          // Реализовано  
void print_socialLinks_menu(void);             // Реализовано   



// Функции вывода данных контактов

//void print_contact(const Contact *contact, int index);
void print_contact(const Contact *contact);                         // Функция вывод информации контакта
void print_contact_var(const Contact *contact, int count, ...);     // Функция вывода информации контакта с изменяемыми параметрами

int print_telephonebook(const TelephoneBook *book);                 // Функция вывода всех контактов

void print_telephone_list(const TelephoneNumberList *list);
void print_emails_list(const EmailList *list);
void print_socials_list(const SocialNetworkList *list);

// Функции для работы с контактом
int input_contact(TelephoneBook *book);                     // Функция добавления контакта
int edit_contact_info(TelephoneBook *book, int index);      // Функция изменения информации контакта




int edit_contact_telephones(Contact *contact);              // Функция редактирования информации "списка телефонов" для одного клиента
int edit_contact_email_adress(Contact *contact);            // Функция редактирования информации "списка электронных адресов" для одного клиента
int edit_contact_social_links(Contact *contact);            // Функция редактирования информации "списка социальных сетей" для одного клиента


void read_line(char *buffer, int size);

#endif