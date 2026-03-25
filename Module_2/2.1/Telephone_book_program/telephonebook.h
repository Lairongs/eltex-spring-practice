#ifndef TELEPHONEBOOK_H
#define TELEPHONEBOOK_H

// ========================================= Статические данные ========================================

#define FIO_LEN 50
#define EMAIL_LEN 100
#define PHONE_LEN 20

#define SOCIALLINK_LEN 150
#define ORGANIZATION_LEN 100

// ==========================================================================================================
// =================================== Структура телефонного справочника ====================================
// ==========================================================================================================



// =================================== Данные об организации ===========================================
typedef struct 
{
    char organizationName[ORGANIZATION_LEN + 1];     // Название организации
    char post[ORGANIZATION_LEN+ 1];                 // Должность в организации

}JobInfo;

// =================================== Структура электронной почты =====================================
typedef struct
{
    char address[EMAIL_LEN + 1];
}Email;

typedef struct
{
    Email *emailList;   // Динамический массив адресов электронной почты
    int size;       // Количество существующих электронных адресов
    int capacity;   // Максимальное количество email под выделенную память 

}EmailList;

// ============================= Структура социальные сети и мессенджеры ===============================
typedef struct 
{
    char socialNetworkLink[SOCIALLINK_LEN + 1];     // Адрес на на страницу в соцсетях или профиль в мессенджерах.
}SocialNetwork;


typedef struct 
{
   SocialNetwork *socialLinksList;      // Динамический массив ссылок на профиль контакта в социальных сетях или мессенджерах
   int size;                        // Количество записанных ссылок 
   int capacity;                    // Максимальное количество ссылок под выделенную память

}SocialNetworkList;

// ==================================== Структура Номера телефонов =====================================

typedef struct 
{
    char phoneNumber[PHONE_LEN + 1];        // Номер телефона

}TelephoneNumber;

typedef struct 
{
    TelephoneNumber *telephoneList;     // Динамический массив номеров телефона
    int size;                           // Количество записанных номеров
    int capacity;                       // Максимальное количество номеров под выделенную память
}TelephoneNumberList;



// ========================================= Структура контакта ========================================

typedef struct 
{   
    char firstName[FIO_LEN + 1];            // Имя
    char lastName[FIO_LEN + 1];             // Фамилия
    char surname[FIO_LEN + 1];              // Отчество 
    TelephoneNumberList telephones;         // Телефоны     
    EmailList emails;                       // Электронная почта
    SocialNetworkList socialLinks;          // Социальные сети и мессенджеры
    JobInfo job;                            // Информация о работе


} Contact;


typedef struct 
{
    Contact *contacts;      // Динамический массив контактов в телефонном справочнике
    int size;               // Количество записанных контактов 
    int capacity;           // Максимальное количество контактов под выделенную память

}TelephoneBook;



// ==================================================================================================
// ========================================== ФУНКЦИИ ===============================================
// ==================================================================================================


void init_telephonebook(TelephoneBook *book);                                    // Функция инициализации телефонного справочника


// ============================= Функции Контакта =============================
 
void init_contact(Contact *contact);                                             // Функция инициализации контакта    
int add_contact(TelephoneBook *book, const Contact *contact);                    // Функция добавления контакта в справочник
/*
    const Contact *contact -> так как при передачи данного контакта в телефонный справочник 
функция должна сохранить целостность данных и не изменять их
*/
void free_contact(Contact *contact);                                             // Функция очистки контакта
int copy_contact(Contact *dest, const Contact *src);                             // Функция копирования контакта 
int remove_contact(TelephoneBook *book, int index);                              // Функция удаления контакта
int edit_contact(TelephoneBook *book, int index, const Contact *new_data);       // Функция редактирования контакта


// ============== Функции для работы с Электронными адресами ==================

void init_email_list(EmailList *emailList);                                      // Функция инициализации списка электронных адресов 
int add_email(EmailList *list, const Email *email);                              // Функция добавления адреса в список электронных адресов
int copy_emails(EmailList *dest, const EmailList *src);                          // Функци копирования электронного адреса 
int remove_emailAddress(EmailList *dest, int index);                             // Функция удаления адреса электронной почты
void free_email_address_list(EmailList *list);                                   // Функция очистки списка адресов электронной почты

// ==================== Функции для работы с Телефонами =======================

void init_telephone_number_list(TelephoneNumberList *telephoneNumberList);        // Функция инициализации списка телефонов
int add_telephones(TelephoneNumberList *list, const TelephoneNumber *telephone);  // Функция добавления телефона в список телефонов
int copy_telephones(TelephoneNumberList *dest, const TelephoneNumberList *src);   // Функция копирования телефона
int remove_telephone(TelephoneNumberList *dest,int index);                        // Функция удаления номера удаления телефона   
void free_telephone_number_list(TelephoneNumberList *list);                        // Функция очистки списка номеров

// ==================== Функции для работы с Соц. Сетями ======================

void init_social_link_list(SocialNetworkList *socialLinks);                      // Функция инициализации списка социальных сетей и мессенджеров
int add_socialLinks(SocialNetworkList *list, const SocialNetwork *link);         // Функция добавления социальной сети в список
int copy_socialLinks(SocialNetworkList *dest, const SocialNetworkList *src);     // функция копирования соц сети
int remove_socilaLink(SocialNetworkList *dest, int index);                       // Функция удаления социальной сети контакта
void free_social_links_list(SocialNetworkList *list);                            // Функция очистки списка соц сетей




// Функции для демонстрации
int load_demo_contacts(TelephoneBook *book);

int add_phone_text(Contact *contact, const char *phone_number);
int add_email_text(Contact *contact, const char *email_text);
int add_social_text(Contact *contact, const char *social_link);

              
// Осталось реализовать 
// --------------------
#endif 