#include <stdio.h>
#include <string.h>
#include "telephonebook.h"
#include <stdlib.h>

void init_telephonebook(TelephoneBook *book){
    if(book == NULL) return;

    book->contacts = NULL;
    book->size=0;
    book->capacity=0;
}

// Функция инициализации телефонных номеров 
void init_telephone_number_list(TelephoneNumberList *telephoneNumberList){

    telephoneNumberList->telephoneList = NULL;
    telephoneNumberList->size = 0;
    telephoneNumberList->capacity = 0;
}

// Функция инициализации электронной почты
void init_email_list(EmailList *emailList){
    
    emailList->emailList = NULL;
    emailList->size = 0;
    emailList->capacity = 0;
}


// Функция иництализации социальных сетей
void init_social_link_list(SocialNetworkList *socialLinks){

    socialLinks->socialLinksList = NULL;
    socialLinks->size = 0;
    socialLinks->capacity = 0;

}

// Функция инициализации контакта
void init_contact(Contact *contact){
    if(contact == NULL) return;

    contact->firstName[0] = '\0';
    contact->lastName[0] = '\0';
    contact->surname[0] = '\0';  

    contact->job.organizationName[0] = '\0';
    contact->job.post[0] = '\0';

    init_email_list(&contact->emails);
    init_social_link_list(&contact->socialLinks);
    init_telephone_number_list(&contact->telephones);
    
}
// =============================================== ДОБАВЛЕНИЕ ДАННЫХ ==============================================
int add_email(EmailList *list, const Email *email){
    if (list == NULL || email == NULL) return 0;

    if(list->size == list->capacity) 
    {
        int newCapacity = (list->capacity == 0) ? 2 : list->capacity*2;
        Email *temp = realloc(list->emailList, newCapacity*sizeof(Email));
        if (temp == NULL) return 0; 

        list->emailList = temp;
        list->capacity = newCapacity;
    }
    Email *dest = &(list->emailList[list->size]);
    strcpy(dest->address,email->address);
    list->size++;

    return 1;
}

int add_telephones(TelephoneNumberList *list, const TelephoneNumber *telephone){
    if(list == NULL || telephone == NULL) return 0;

    if(list->size == list->capacity){
        int newCapacity = (list->capacity == 0) ? 2 : list->capacity*2;
        TelephoneNumber *temp = realloc(list->telephoneList, newCapacity*sizeof(TelephoneNumber));
        if(temp == NULL) return 0;

        list->telephoneList=temp;
        list->capacity = newCapacity;
    }

    TelephoneNumber *dest = &(list->telephoneList[list->size]);
    strcpy(dest->phoneNumber, telephone->phoneNumber);
    list->size++;
    
    return 1; 
}

int add_socialLinks(SocialNetworkList *list, const SocialNetwork *link)
{
    if(list == NULL || link == NULL) return 0;

    if(list->size == list->capacity){
        int newCapacity = (list->capacity == 0) ? 2 : list->capacity*2;
        SocialNetwork *temp = realloc(list->socialLinksList, newCapacity*sizeof(SocialNetwork));
        if(temp == NULL) return 0;

        list->socialLinksList=temp;
        list->capacity = newCapacity;
    }

    SocialNetwork *dest = &(list->socialLinksList[list->size]);
    strcpy(dest->socialNetworkLink, link->socialNetworkLink);
    list->size++;
    
    return 1; 
}


// Добавление контакта
int add_contact(TelephoneBook *book, const Contact *contact){
    if(book == NULL || contact == NULL) return 0;                                   // Если значение 0, или телефонный справочник, или контакт не существуют 

    if(book->size == book->capacity){
        int newCapacity = (book->capacity == 0) ? 2 : book->capacity*2;
        Contact *temp = realloc(book->contacts,newCapacity * sizeof(Contact));
        if(temp == NULL) return 0;                                                 // Если значение 0, значит системе не удалось выделить память       
        
        book->contacts = temp;
        book->capacity = newCapacity;
    }
    Contact *dest = &(book->contacts[book->size]);
    init_contact(dest);

    if (!copy_contact(dest, contact)) 
    {
        free_contact(dest);
        return 0;
    }

    // Теперь нужно написать функцию для копирования данных 

    book->size++; 
    return 1;
}

// ============================================== КОПИРОВАНИЕ ДАННЫХ ==============================================

int copy_contact(Contact *dest, const Contact *src){

    if (dest == NULL || src == NULL) return 0;
    
    strcpy(dest->firstName,src->firstName);
    strcpy(dest->lastName,src->lastName);
    strcpy(dest->surname,src->surname);

    strcpy(dest->job.organizationName, src->job.organizationName);
    strcpy(dest->job.post, src->job.post);
    
    if (!copy_emails(&dest->emails, &src->emails))
    {
        free_contact(dest);
        return 0;
    }

    if (!copy_telephones(&dest->telephones, &src->telephones))
    {
        free_contact(dest);
        return 0;
    }

    if (!copy_socialLinks(&dest->socialLinks, &src->socialLinks))
    {
        free_contact(dest);
        return 0;
    }

    return 1;
}

int copy_emails(EmailList *dest, const EmailList *src){

    if(dest == NULL || src == NULL) return 0;

    init_email_list(dest);

    if(src->size > 0)
    {
        dest->emailList = malloc(src->capacity * sizeof(Email));
        if(dest->emailList == NULL) return 0;

        for(int i = 0; i < src->size; i++)
        {
            dest->emailList[i] = src->emailList[i];
        }
        dest->size = src->size;
        dest->capacity = src->capacity; 
    }
    return 1;
}
int copy_telephones(TelephoneNumberList *dest, const TelephoneNumberList *src)
{
    if(dest == NULL || src == NULL) return 0;

    init_telephone_number_list(dest);

    if(src->size > 0)
    {
        dest->telephoneList = malloc(src->capacity * sizeof(TelephoneNumber));
        if(dest->telephoneList == NULL) return 0;

        for(int i = 0; i < src->size; i++)
        {
            dest->telephoneList[i] = src->telephoneList[i];
        }
        dest->size = src->size;
        dest->capacity = src->capacity; 
    }
    return 1;
}
int copy_socialLinks(SocialNetworkList *dest, const SocialNetworkList *src)
{
    if(dest == NULL || src == NULL) return 0;

    init_social_link_list(dest);

    if(src->size > 0)
    {
        dest->socialLinksList = malloc(src->capacity * sizeof(SocialNetwork));
        if(dest->socialLinksList == NULL) return 0;

        for(int i = 0; i < src->size; i++)
        {
            dest->socialLinksList[i] = src->socialLinksList[i];
        }
        dest->size = src->size;
        dest->capacity = src->capacity; 
    }
    return 1;
}

// ================================================================================================================
// ============================================ РЕДАКТИРОВАНИЕ ДАННЫХ =============================================

int edit_contact(TelephoneBook *book, int index, const Contact *new_data)
{
    if (book == NULL || new_data == NULL) return 0;

    if (index < 0 || index >= book->size)
    {
        return 0;
    }

    Contact temp;
    init_contact(&temp);

    if (!copy_contact(&temp, new_data))
    {
        free_contact(&temp);
        return 0;
    }

    free_contact(&book->contacts[index]);

    if (!copy_contact(&book->contacts[index], &temp))
    {
        free_contact(&temp);
        return 0;
    }

    free_contact(&temp);
    return 1;
}
/**/

// ================================================================================================================
// ========================================== ОЧИСТКА ДАННЫХ И УДАЛЕНИЕ ===========================================
// ================================================================================================================

// Освобождение данных контакта целиком

void free_contact(Contact *contact)
{
    if (contact == NULL)
    {
        return;
    }

    free(contact->emails.emailList);
    free(contact->telephones.telephoneList);
    free(contact->socialLinks.socialLinksList);

    init_contact(contact);
}

void free_telephone_number_list(TelephoneNumberList *list)
{
    if (list == NULL)
    {
        return;
    }

    free(list->telephoneList);
    list->telephoneList = NULL;
    list->size = 0;
    list->capacity = 0;
}

void free_email_address_list(EmailList *list)
{
    if (list == NULL)
    {
        return;
    }

    free(list->emailList);
    list->emailList = NULL;
    list->size = 0;
    list->capacity = 0;
}
void free_social_links_list(SocialNetworkList *list)
{
    if (list == NULL)
    {
        return;
    }

    free(list->socialLinksList);
    list->socialLinksList = NULL;
    list->size = 0;
    list->capacity = 0;
}

// Удаление контакта
int remove_contact(TelephoneBook *book, int index)
{
    if(book == NULL) return 0; 
    if(index < 0 || index >= book->size) return 0;

    Contact *contact = &book->contacts[index];
    free_contact(contact);

    for(int i = index; i < book->size-1; i++)
    {
        book->contacts[i] = book->contacts[i+1];
    }

    book->size--;
    init_contact (&book->contacts[book->size]);
    return 1;

}

// Удаление номера телефона
int remove_telephone(TelephoneNumberList *dest, int index)
{
    if(dest == NULL) return 0; 
    if(index < 0 || index >= dest->size) return 0;

    for(int i = index; i < dest->size-1; i++)
    {
        dest->telephoneList[i] = dest->telephoneList[i+1];
    }
    dest->size--;
    dest->telephoneList[dest->size].phoneNumber[0]='\0';
    return 1;
}
// Удаление электронного адреса почты 
int remove_emailAddress(EmailList *dest, int index)
{
    if(dest == NULL) return 0; 
    if(index < 0 || index >= dest->size) return 0;

    for(int i = index; i < dest->size-1; i++)
    {
        dest->emailList[i] = dest->emailList[i+1];
    }
    dest->size--;
    dest->emailList[dest->size].address[0] = '\0';
    return 1;
}
// Удаление ссылки на социальную сеть контакта
int remove_socilaLink(SocialNetworkList *dest, int index)
{
    if(dest == NULL) return 0; 
    if(index < 0 || index >= dest->size) return 0;

    for(int i = index; i < dest->size-1; i++)
    {
        dest->socialLinksList[i] = dest->socialLinksList[i+1];
    }
    dest->size--;
    dest->socialLinksList[dest->size].socialNetworkLink[0]='\0';
    return 1;
}

// ==============================================================================================================

int add_phone_text(Contact *contact, const char *phone_number)
{
    TelephoneNumber temp_phone;

    if (contact == NULL || phone_number == NULL)
    {
        return 0;
    }

    temp_phone.phoneNumber[0] = '\0';
    strncpy(temp_phone.phoneNumber, phone_number, PHONE_LEN);
    temp_phone.phoneNumber[PHONE_LEN] = '\0';

    return add_telephones(&contact->telephones, &temp_phone);
}

int add_email_text(Contact *contact, const char *email_text)
{
    if (contact == NULL || email_text == NULL)
    {
        return 0;
    }

    Email temp_email;
    temp_email.address[0] = '\0';

    strncpy(temp_email.address, email_text, EMAIL_LEN);
    temp_email.address[EMAIL_LEN] = '\0';

    return add_email(&contact->emails, &temp_email);
}

int add_social_text(Contact *contact, const char *social_link)
{
    if (contact == NULL || social_link == NULL)
    {
        return 0;
    }

    SocialNetwork temp_socialLink;
    temp_socialLink.socialNetworkLink[0] = '\0';

    strncpy(temp_socialLink.socialNetworkLink, social_link, SOCIALLINK_LEN);
    temp_socialLink.socialNetworkLink[SOCIALLINK_LEN] = '\0';

    return add_socialLinks(&contact->socialLinks, &temp_socialLink);
}

int load_demo_contacts(TelephoneBook *book)
{
    Contact contact;

    if (book == NULL)
    {
        return 0;
    }

    /* 1. Только базовая информация */
    init_contact(&contact);
    strcpy(contact.lastName, "Иванов");
    strcpy(contact.firstName, "Иван");
    if (!add_contact(book, &contact)) return 0;

    /* 2. Базовая + один телефон */
    init_contact(&contact);
    strcpy(contact.lastName, "Петров");
    strcpy(contact.firstName, "Пётр");
    strcpy(contact.surname, "Алексеевич");
    if (!add_phone_text(&contact, "+7-913-100-20-30")) { free_contact(&contact); return 0; }
    if (!add_contact(book, &contact)) return 0;

    /* 3. ФИО + 2 телефона + email */
    init_contact(&contact);
    strcpy(contact.lastName, "Сидорова" );
    strcpy(contact.firstName, "Анна" );
    strcpy(contact.surname, "Викторовна");
    if (!add_phone_text(&contact, "+7-923-555-11-22")) { free_contact(&contact); return 0; }
    if (!add_phone_text(&contact, "+7-923-555-33-44")) { free_contact(&contact); return 0; }
    if (!add_email_text(&contact, "anna.sidorova@mail.ru")) { free_contact(&contact); return 0; }
    if (!add_contact(book, &contact)) return 0;

    /* 4. ФИО + работа + email */
    init_contact(&contact);
    strcpy(contact.lastName, "Кузнецов");
    strcpy(contact.firstName, "Дмитрий");
    strcpy(contact.surname, "Игоревич");
    strcpy(contact.job.organizationName, "ООО Сигма");
    strcpy(contact.job.post, "Инженер-программист");
    if (!add_email_text(&contact, "d.kuznetsov@sigma.ru")) { free_contact(&contact); return 0; }
    if (!add_contact(book, &contact)) return 0;

    /* 5. ФИО + 2 email + соцсеть */
    init_contact(&contact);
    strcpy(contact.lastName, "Орлова");
    strcpy(contact.firstName, "Мария");
    if (!add_email_text(&contact, "m.orlova@gmail.com")) { free_contact(&contact); return 0; }
    if (!add_email_text(&contact, "orlovam@bk.ru")) { free_contact(&contact); return 0; }
    if (!add_social_text(&contact, "https://vk.com/maria_orlova")) { free_contact(&contact); return 0; }
    if (!add_contact(book, &contact)) return 0;

    /* 6. ФИО + работа + 2 телефона + 2 соцсети */
    init_contact(&contact);
    strcpy(contact.lastName, "Смирнов");
    strcpy(contact.firstName, "Алексей");
    strcpy(contact.surname, "Павлович");
    strcpy(contact.job.organizationName, "АО ТехноСервис");
    strcpy(contact.job.post, "Системный администратор");
    if (!add_phone_text(&contact, "+7-983-777-00-11")) { free_contact(&contact); return 0; }
    if (!add_phone_text(&contact, "+7-983-777-00-22")) { free_contact(&contact); return 0; }
    if (!add_social_text(&contact, "https://t.me/alex_sm_admin")) { free_contact(&contact); return 0; }
    if (!add_social_text(&contact, "https://vk.com/alex.smirnov")) { free_contact(&contact); return 0; }
    if (!add_contact(book, &contact)) return 0;

    /* 7. Повторяющееся ФИО №1 */
    init_contact(&contact);
    strcpy(contact.lastName, "Волков");
    strcpy(contact.firstName, "Андрей");
    strcpy(contact.surname, "Сергеевич");
    if (!add_phone_text(&contact, "+7-905-111-22-33")) { free_contact(&contact); return 0; }
    if (!add_email_text(&contact, "andrey.volkov.personal@yandex.ru")) { free_contact(&contact); return 0; }
    if (!add_contact(book, &contact)) return 0;

    /* 8. Повторяющееся ФИО №2, но другой телефон */
    init_contact(&contact);
    strcpy(contact.lastName, "Волков");
    strcpy(contact.firstName, "Андрей");
    strcpy(contact.surname, "Сергеевич");
    if (!add_phone_text(&contact, "+7-905-444-55-66")) { free_contact(&contact); return 0; }
    if (!add_email_text(&contact, "andrey.volkov.work@company.ru")) { free_contact(&contact); return 0; }
    strcpy(contact.job.organizationName, "ООО АльфаПроект");
    strcpy(contact.job.post, "Проектный менеджер");
    if (!add_contact(book, &contact)) return 0;

    /* 9. Только ФИО + соцсеть */
    init_contact(&contact);
    strcpy(contact.lastName, "Фёдорова");
    strcpy(contact.firstName, "Елена");
    strcpy(contact.surname, "Максимовна");
    if (!add_social_text(&contact, "https://t.me/elena_fedorova")) { free_contact(&contact); return 0; }
    if (!add_contact(book, &contact)) return 0;

    /* 10. Максимально наполненный контакт */
    init_contact(&contact);
    strcpy(contact.lastName, "Николаев");
    strcpy(contact.firstName, "Роман");
    strcpy(contact.surname, "Денисович");
    strcpy(contact.job.organizationName, "ГК ИнфоТех");
    strcpy(contact.job.post, "Ведущий аналитик");
    if (!add_phone_text(&contact, "+7-901-123-45-67")) { free_contact(&contact); return 0; }
    if (!add_phone_text(&contact, "+7-901-765-43-21")) { free_contact(&contact); return 0; }
    if (!add_email_text(&contact, "roman.nikolaev@infotech.ru")) { free_contact(&contact); return 0; }
    if (!add_email_text(&contact, "r.nikolaev@gmail.com")) { free_contact(&contact); return 0; }
    if (!add_social_text(&contact, "https://vk.com/roman_nikolaev")) { free_contact(&contact); return 0; }
    if (!add_social_text(&contact, "https://t.me/roman_nikolaev")) { free_contact(&contact); return 0; }
    if (!add_contact(book, &contact)) return 0;

    return 1;
}