#include <stdio.h>
#include <string.h>
#include "user_interface.h"
#include <stdarg.h>

void read_line(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

// int select_menu_index(){

//     int number_case;
//     printf("Выберите необходимый пункт из списка (Только число!): ");
//     if (scanf("%d", &number_case) != 1)
//     {
//         printf("Ошибка ввода. Нужно ввести число.\n");
//         while (getchar() != '\n');
//     }
        
//     while (getchar() != '\n');
//     printf("%d", number_case);
//     return number_case;
// }

// =============================================== Самый главный блок ===============================================

void main_IO_telephoneBook(TelephoneBook *book){
  
    if(book == NULL) return;
    int number_case;
    
    while(1){
        print_main_menu();   // Вывод главного интерфейса
        if (scanf("%d", &number_case) != 1)
        {
            printf("Ошибка ввода. Нужно ввести число.\n");
            while (getchar() != '\n');
            continue;
        }
        
        while (getchar() != '\n');

        switch (number_case)
        {
        case 0:
            return;
        case 1:
            input_contact(book);
            break;
        case 2:       
            if(!print_telephonebook(book))
            {
                printf("Телефонный справочник пустой! \n");
            }
            else
            {               
                int loc_val;
                printf("\n\nВыберите номер контакта, который хотите изменить!\n");
                printf("Выбранный индекс >> ");
                if (scanf("%d", &loc_val) != 1)
                {
                    printf("Ошибка ввода. Нужно ввести число.\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                edit_contact_info(book, loc_val);    
            }    
            break;
        case 3:
            if(!print_telephonebook(book))
            {
                printf("Телефонный справочник пустой! \n");
            }
            else
            {               
                int loc_val;
                printf("\n\nВыберите номер контакта, который хотите удалить!\n");
                printf("Выбранный индекс >> ");
                if (scanf("%d", &loc_val) != 1)
                {
                    printf("Ошибка ввода. Нужно ввести число.\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                remove_contact(book, loc_val-1);    
            }   
            
            break;

        case 4:
            if(!print_telephonebook(book))
            {
                printf("Телефонный справочник пустой! \n");
            }
            break;
        case 5:
        {
            if(!print_telephonebook(book))
            {
                printf("Телефонный справочник пустой! \n");
            }
            else
            {               
                int loc_val;
                printf("\n\nВыберите номер контакта, который хотите посмотреть!\n");
                printf("Выбранный индекс >> ");
                if (scanf("%d", &loc_val) != 1)
                {
                    printf("Ошибка ввода. Нужно ввести число.\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                print_contact(&book->contacts[loc_val-1]);    
            }   
            break; 
        }
            
        default:
            printf("Неверный пункт меню.\n");
            break;     
        }   
        
    }

}


// ==================================================================================================================
// ============================================== ФУНКЦИИ ВЫВОДА МЕНЮ ===============================================
// ==================================================================================================================

void print_main_menu(void)
{   
    
    printf("\n========== Телефонный справочник ==========\n");
    printf("1. Добавить контакт\n");
    printf("2. Редактировать контакт\n");
    printf("3. Удалить контакт\n");
    printf("4. Показать все контакты\n");
    printf("5. Показать конкретный контакт\n");
    printf("0. Выход\n\n");

    printf("Выберите необходимый пункт из списка (Только число!): ");

}

void print_add_contact_menu(void)
{
    // Меню "Добавления контакта"
    printf("\n======= Меню доп. параметров контакта =======\n");
    printf("\nДополнительный функционал: \n");
    printf("1. Сохранить контакт\n");
    printf("2. Вывести информацию о контакте\n");
    printf("3. Добавить номер телефона\n");
    printf("4. Добавить адрес электронной почты\n");
    printf("5. Добавить место работы\n");
    printf("6. Добавить ссылку на социальную сеть или мессенджер\n");
    printf("0. Отмена создания контакта\n\n");

}

void print_edit_contact_menu(void)
{
    // Меню "Редактирование контакта"
    printf("\n======= Редактирование контакта =======\n");
    printf("\nДополнительный функционал: \n");
    printf("1. Сохранить изменения контакта\n");
    printf("2. Вывести информацию о контакте\n");
    printf("=================\n");
    printf("3. Изменить фамилию контакта\n");
    printf("4. Изменить имя контакта\n");
    printf("5. Изменить отчество контакта\n");
    printf("=================\n");

    printf("6. Изменить номер телефона\n");
    printf("7. Изменить адрес электронной почты\n");
    printf("8. Изменить место работы\n");
    printf("9. Изменить ссылку на социальную сеть или мессенджер\n");
    printf("=================\n");

    printf("0. Отмена изменения контакта\n\n");
    
    
    printf("Выберите необходимый пункт из списка (Только число!): ");
}

// Меню списка телефонов контакта
void print_contact_telephones_menu(void)
{
    printf("\n===== Меню редактирование <списка номеров телефона> =====\n");
    printf("1. Сохранить изменения списка телефонов контакта\n");
    printf("2. Вывести номера контакта\n");
    printf("3. Добавить номер контакта\n");
    printf("4. Изменить существующий номер контакта\n");
    printf("5. Удалить номер контакта\n\n");
    printf("0. Отмена изменения номеров контакта\n\n");

    printf("Выберите необходимый пункт из списка (Только число!): ");
}

// Меню списка электронных адресов контакта
void print_contact_emails_menu(void)
{
    printf("\n===== Меню редактирование <списка электронных адресов> =====\n");    
    printf("1. Сохранить изменения списка электронной почты контакта\n");
    printf("2. Вывести список электронной почты контакта\n");
    printf("3. Добавить электронную почту контакту\n");
    printf("4. Изменить существующую электронную почту контакта\n");
    printf("5. Удалить электронную почту контакта\n");
    printf("0. Отмена изменения списка электронной почты\n\n");

    printf("Выберите необходимый пункт из списка (Только число!): ");
}

// Меню списка соц сетей контакта
void print_socialLinks_menu(void)
{
    printf("\n===== Меню редактирование <списка социальных сетей> =====\n");    
    printf("1. Сохранить изменения списка социальных сетей контакта\n");
    printf("2. Вывести список социальных сетей контакта\n");
    printf("3. Добавить социальную сеть контакту\n");
    printf("4. Изменить существующую социальную сеть у контакта\n");
    printf("5. Удалить существующую социальную сеть у контакта\n");
    printf("0. Отмена изменения списка социальных сетей\n\n");

    printf("Выберите необходимый пункт из списка (Только число!): ");
}
// ==================================================================================================================
// ============================================ ФУНКЦИИ ВЫВОДА КОНТАКТОВ ============================================
// ==================================================================================================================

enum PrintField
{
    FIELD_NAME,
    FIELD_JOB,
    FIELD_PHONES,
    FIELD_EMAILS,
    FIELD_SOCIALS
};

void print_contact_var(const Contact *contact, int count, ...)
{
    if (contact == NULL)
    {
        return;
    }

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        int field = va_arg(args, int);

        switch (field)
        {
            case FIELD_NAME:
                printf("Фамилия: %s\n", contact->lastName);
                printf("Имя: %s\n", contact->firstName);
                printf("Отчество: %s\n", contact->surname);
                break;

            case FIELD_JOB:
                if (contact->job.organizationName[0] != '\0')
                    printf("Организация: %s\n", contact->job.organizationName);

                if (contact->job.post[0] != '\0')
                    printf("Должность: %s\n", contact->job.post);
                break;

            case FIELD_PHONES:
                if (contact->telephones.size > 0)
                {
                    printf("Телефоны:\n");
                    for (int j = 0; j < contact->telephones.size; j++)
                    {
                        printf("  %d) %s\n", j + 1, contact->telephones.telephoneList[j].phoneNumber);
                    }
                }
                break;

            case FIELD_EMAILS:
                if (contact->emails.size > 0)
                {
                    printf("Email:\n");
                    for (int j = 0; j < contact->emails.size; j++)
                    {
                        printf("  %d) %s\n", j + 1, contact->emails.emailList[j].address);
                    }
                }
                break;

            case FIELD_SOCIALS:
                if (contact->socialLinks.size > 0)
                {
                    printf("Соцсети и мессенджеры:\n");
                    for (int j = 0; j < contact->socialLinks.size; j++)
                    {
                        printf("  %d) %s\n", j + 1, contact->socialLinks.socialLinksList[j].socialNetworkLink);
                    }
                }
                break;
        }
    }

    va_end(args);
}

// Вывод контакта
void print_contact(const Contact *contact)
{
    if (contact == NULL)
    {
        return;
    }

    //printf("\nКонтакт #%d\n", index + 1);
    printf("Фамилия: %s\n", contact->lastName);
    printf("Имя: %s\n", contact->firstName);
    printf("Отчество: %s\n", contact->surname);

    if (contact->job.organizationName[0] != '\0')
    {
        printf("Организация: %s\n", contact->job.organizationName);
    }

    if (contact->job.post[0] != '\0')
    {
        printf("Должность: %s\n", contact->job.post);
    }

    if (contact->telephones.size > 0)
    {
        printf("Телефоны:\n");
        for (int i = 0; i < contact->telephones.size; i++)
        {
            printf("  %d) %s\n", i + 1, contact->telephones.telephoneList[i].phoneNumber);
        }
    }

    if (contact->emails.size > 0)
    {
        printf("Email:\n");
        for (int i = 0; i < contact->emails.size; i++)
        {
            printf("  %d) %s\n", i + 1, contact->emails.emailList[i].address);
        }
    }

    if (contact->socialLinks.size > 0)
    {
        printf("Соцсети и мессенджеры:\n");
        for (int i = 0; i < contact->socialLinks.size; i++)
        {
            printf("  %d) %s\n", i + 1, contact->socialLinks.socialLinksList[i].socialNetworkLink);
        }
    }
}

// Вывод телефонного справочника
int print_telephonebook(const TelephoneBook *book)
{

    if(book == NULL) return 0;
    if(book->size == 0) return 0;
    printf("\n==================================================================================================================\n");

    for(int i = 0; i < book->size; i++)
    {
        printf("\n======================================\n");
        printf("Номер в записной книжке - %d \n", i+1);
        print_contact(&book->contacts[i]);
    }
        
    printf("\n==================================================================================================================\n");

    return 1;
}

void print_telephone_list(const TelephoneNumberList *list)
{
    if (list == NULL || list->size == 0)
    {
        printf("Список телефонов пуст.\n");
        return;
    }

    printf("Телефоны:\n");
    for (int i = 0; i < list->size; i++)
    {
        printf("  %d) %s\n", i + 1, list->telephoneList[i].phoneNumber);
    }
}

void print_emails_list(const EmailList *list)
{
    if (list == NULL || list->size == 0)
    {
        printf("Список телефонов пуст.\n");
        return;
    }

    printf("Телефоны:\n");
    for (int i = 0; i < list->size; i++)
    {
        printf("  %d) %s\n", i + 1, list->emailList[i].address);
    }
}
void print_socials_list(const SocialNetworkList *list)
{
    if (list == NULL || list->size == 0)
    {
        printf("Список телефонов пуст.\n");
        return;
    }

    printf("Телефоны:\n");
    for (int i = 0; i < list->size; i++)
    {
        printf("  %d) %s\n", i + 1, list->socialLinksList[i].socialNetworkLink);
    }
}


// ==================================================================================================================
// =========================================== ФУНКЦИЯ ДОБАВЛЕНИЯ КОНТАКТА ========================================== 
// ==================================================================================================================

int input_contact(TelephoneBook *book)
{
    if(book == NULL) return 0;

    Contact contact;
    init_contact(&contact);

    printf("\n========== Создание контакта ===========");

    printf("\nВведите фамилию: ");
    read_line(contact.lastName, FIO_LEN);
    if(contact.lastName[0] == '\0'){
        printf("\nОшибка создания контакта: фамилия обязательный параметр.\n");
        free_contact(&contact);
        return 0;
    }

    printf("Введите имя: ");
    read_line(contact.firstName, FIO_LEN);
    if(contact.firstName[0] == '\0'){
        printf("\nОшибка создания контакта: имя обязательный параметр.\n");
        free_contact(&contact);
        return 0;
    }

    printf("Введите отчество (можно оставить пустым): ");
    read_line(contact.surname, FIO_LEN);
    
    int number_case;

    while (1)
    {   
        print_add_contact_menu();
        if (scanf("%d", &number_case) != 1)
        {
            printf("Ошибка ввода. Нужно ввести число.\n");
            while (getchar() != '\n');
            continue;
        }  
        while (getchar() != '\n');
        printf("\n");
        switch (number_case)
        {
        case 0:
            free_contact(&contact);                
            printf("Отмена создания контакта.\n");
            return 0;

        case 1:
            if (add_contact(book, &contact))
            {
                free_contact(&contact);
                printf("Контакт добавлен.\n");
                return 1;
            }
            else
            {
                free_contact(&contact);
                printf("Ошибка добавления контакта.\n");
                return 0;
            }

        case 2:
            print_contact(&contact);    
            break;

        case 3:
        {
            TelephoneNumber temp_telephone;

            printf("Введите номер телефона: ");
            read_line(temp_telephone.phoneNumber, PHONE_LEN);
        
            if(add_telephones(&contact.telephones, &temp_telephone))
            {
                printf("Номер телефона добавлен.\n");
            }
            else
            {
                printf("Ошибка добавления номера телефона.\n");
            }
            break;
        }
        case 4:
        {
            Email temp_email;

            printf("Введите адрес электронной почты: ");
            read_line(temp_email.address, EMAIL_LEN);

            if(add_email(&contact.emails, &temp_email))
            {
                printf("Адрес электронной почты добавлен.\n");
            }
            else
            {
                printf("Ошибка добавления адреса электронной почты.\n");
            }
            break;  
        } 
        case 5:
        {
            printf("Введите организацию (можно оставить пустым): ");
            read_line(contact.job.organizationName, ORGANIZATION_LEN);

            printf("Введите должность (можно оставить пустым): ");
            read_line(contact.job.post, ORGANIZATION_LEN);   
            break;
        }
                   
        case 6:
        {
            SocialNetwork temp_socialLink;

            printf("Введите ссылку на соц. сеть или мессенджер: ");
            read_line(temp_socialLink.socialNetworkLink, SOCIALLINK_LEN);
            if(add_socialLinks(&contact.socialLinks, &temp_socialLink))
            {
                printf("Ссылка на социальную сеть или мессенджер добавлена.\n");
            }
            else
            {
                printf("Ошибка добавления ссылки на социальную сеть или мессенджер.\n");
            }
            break;
        }  
        default:
            printf("Неверный пункт меню.\n");
            break;            
        }
    } 
}

// ==================================================================================================================
// =========================================== ФУНКЦИЯ РЕДАКТИРОВАНИЯ КОНТАКТА ========================================== 
// ==================================================================================================================

int edit_contact_info(TelephoneBook *book, int index){
    if (book == NULL) return 0;
    
    if (index < 0 || index > book->size)
    {
        return 0;
    }

    int number_case;
    Contact new_contact;
    init_contact(&new_contact);
    if(!copy_contact(&new_contact, &book->contacts[index-1]))
    {
        free_contact(&new_contact);
        printf("Ошибка редактирования контакта!\n");
        return 0;
    }
    
    printf("=============================== Информация о контакте ===============================\n");
    print_contact(&new_contact);
    printf("=====================================================================================\n\n");

    while(1){

        print_edit_contact_menu();   // Вывод интерфейса редактирования контакта

        if (scanf("%d", &number_case) != 1)
        {
            printf("Ошибка ввода. Нужно ввести число.\n");
            while (getchar() != '\n');
            continue;
        }
        
        while (getchar() != '\n');
    
        char fio_string[FIO_LEN];
        switch (number_case)
        {
            case 0:
                free_contact(&new_contact);                
                printf("Отмена изменения контакта.\n");
                return 0;

            case 1:     // Сохранить изменения контакта
            {
                if(edit_contact(book, index-1, &new_contact))
                {
                    printf("Контакт успешно изменен!!!\n");
                    free_contact(&new_contact);
                    return 1;
                }
                else    
                {
                    free_contact(&new_contact);
                    printf("Ошибка редактирования контакта!\n");
                    return 0;
                }   
            }
            
            case 2:    // Вывести информацию о контакте 
            {
                print_contact(&new_contact);
                break;
            }
            case 3:    // Изменить фамилию контакта
            {
                printf("Предыдущая фамилия контакта: %s", new_contact.lastName);
                printf("\nВведите новую фамилию: ");
                read_line(fio_string, FIO_LEN);
                if(fio_string[0] == '\0')
                {
                    printf("\nОшибка изменения! Фамилия обязательный параметр и не может быть пустой.\n");
                }
                else strcpy(new_contact.lastName, fio_string);
                break;
            }
            case 4:     // Изменить имя контакта
            {
                printf("Предыдущее имя контакта: %s", new_contact.firstName);
                printf("\nВведите имя: ");
                read_line(fio_string, FIO_LEN);
                if(fio_string[0] == '\0'){
                    printf("\nОшибка изменения! Имя обязательный параметр и не может быть пустым.\n");
                }
                else strcpy(new_contact.firstName, fio_string);
                break;
            }
            case 5:    // Изменить отчество 
            {
                printf("Предыдущее отчество контакта: %s", new_contact.surname);
                printf("\nВведите отчество (можно оставить пустым): ");
                read_line(new_contact.surname, FIO_LEN);   
                break;
            }
            case 6:    // Изменение списка номеров телефона
            {                 
                if(edit_contact_telephones(&new_contact))
                {
                    printf("Список номеров телефона успешно изменен!\n");
                }    
                else
                {
                    printf("Изменение списка номеров телефона отменено.\n");
                }
                break;
            }
            case 7:    // Изменение списка электронных адресов
            {                 
                if(edit_contact_email_adress(&new_contact))
                {
                    printf("Список электронных адресов успешно изменен!\n");
                }    
                else
                {
                    printf("Изменение списка электронных адресов отменено.\n");
                }
                break;
            }

            case 8: 
                printf("Предыдущая должность контакта: %s\n", new_contact.job.post);
                printf("Введите новую должность: ");
                read_line(fio_string, ORGANIZATION_LEN);

                if (fio_string[0] == '\0')
                {
                    printf("\nОшибка изменения! Должность не может быть пустой.\n");
                }
                else
                {
                    strcpy(new_contact.job.post, fio_string);
                }
                break;
            case 9:
                if(edit_contact_social_links(&new_contact))
                {
                    printf("Список социальных сетей контакта успешно изменен!\n");
                }    
                else
                {
                    printf("Изменение списка социальных сетей контакта отменено.\n");
                }
                break;
            default:
                printf("Неверный пункт меню.\n");
                break;
        }
    }
}

int edit_contact_telephones(Contact *contact)
{
    if(contact == NULL ) return 0;

    TelephoneNumberList new_list;
    init_telephone_number_list(&new_list);
    if(!copy_telephones(&new_list, &contact->telephones))
    {
        printf("Ошибка изменения телефонных номеров контакта");
        free_telephone_number_list(&new_list);
        return 0;
    }                                            

    int number_case;
    while(1)
    {
        print_contact_telephones_menu();   // Вывод интерфейса редактирования контакта

        if (scanf("%d", &number_case) != 1)
        {
            printf("Ошибка ввода. Нужно ввести число.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        switch (number_case)
        {
            case 0:     // Отмена изменения номеров контакта
                free_telephone_number_list(&new_list);
                return 0;

            case 1:     // Сохранить изменения списка телефонов контакта
            {
                if(copy_telephones(&contact->telephones, &new_list))
                {
                    free_telephone_number_list(&new_list);
                    return 1;
                }
                else
                {
                    free_telephone_number_list(&new_list);
                    return 0;
                } 
            }           
            case 2:     // Вывести номера контакта
                print_telephone_list(&new_list);
                break;

            case 3:     // Добавить номер контакта
            {
                TelephoneNumber temp_telephone;

                printf("\nВведите новый номер телефона: ");
                read_line(temp_telephone.phoneNumber, PHONE_LEN);
            
                if(add_telephones(&new_list, &temp_telephone))
                {
                    printf("Номер телефона добавлен.\n");
                }
                else
                {
                    printf("Ошибка добавления номера телефона.\n");
                }
                break;
            }

            case 4:     // Изменить существующий номер контакта
            {
                if(new_list.size == 0) printf("Список контактов пуст\n");
                else
                {   printf("Введите индекс изменяемого номера телефона. Для отмены операции введите 0\n");
                    printf("Выбранный индекс >> ");    
                    if (scanf("%d", &number_case) != 1)
                    {
                        printf("Ошибка ввода. Нужно ввести число.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');
                    if(number_case == 0) continue;
                    if(number_case > 0 && number_case <= new_list.size )
                    {
                        printf("Изменяемый номер телефона: %s \n", new_list.telephoneList[number_case-1].phoneNumber);
                        printf("Введите новый номер телефона: ");
                        read_line(new_list.telephoneList[number_case-1].phoneNumber, PHONE_LEN);
                        printf("\n\nНомер телефона успешно изменен!\n");
                    }
                }
                break;
            }
            case 5:     // Удалить номер контакта
            {
                if(new_list.size == 0) printf("Список контактов пуст\n");
                else
                {
                    printf("Введите индекс удаляемого номера телефона. Для отмены операции введите 0\n");
                    printf("Выбранный индекс >> "); 
                    if (scanf("%d", &number_case) != 1)
                    {
                        printf("Ошибка ввода. Нужно ввести число.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');
                    if(number_case == 0) continue;
                    else
                    {
                        if(remove_telephone(&new_list, number_case-1))
                        {
                            printf("Номер телефона удален успешно\n");
                        }
                        else
                        {
                            printf("Ошибка! Неудалось удалить номер телефона\n");
                        }
                    }
                }
                break;       
            }
            default:
                printf("Неверный пункт меню.\n");
                break;
        }
    }
}

// Изменение электронных адресов
int edit_contact_email_adress(Contact *contact)
{
    if(contact == NULL ) return 0;

    EmailList new_list;
    init_email_list(&new_list);
    if(!copy_emails(&new_list, &contact->emails))
    {
        printf("изменения списка электронных адресов контакта");
        free_email_address_list(&new_list);
        return 0;
    }                                            

    int number_case;
    while(1)
    {
        print_contact_emails_menu();   // Вывод интерфейса редактирования контакта

        if (scanf("%d", &number_case) != 1)
        {
            printf("Ошибка ввода. Нужно ввести число.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        switch (number_case)
        {
            case 0:     // Отмена изменения списка электронной почты
                free_email_address_list(&new_list);
                return 0;

            case 1:     // Сохранить изменения списка электронной почты контакта
            {
                if(copy_emails(&contact->emails, &new_list))
                {
                    free_email_address_list(&new_list);
                    return 1;
                }
                else
                {
                    printf("Ошибка изменения списка электронных адресов контакта");
                    free_email_address_list(&new_list);
                    return 0;
                } 
            }           
            case 2:     // Вывести список электронной почты контакта
                print_emails_list(&new_list);
                break;

            case 3:     // Добавить электронную почту контакту
            {
                Email temp_email;
                
                printf("\nВведите новый электронный адрес: ");
                read_line(temp_email.address, EMAIL_LEN);
            
                if(add_email(&new_list, &temp_email))
                {
                    printf("Электронный адрес добавлен.\n");
                }
                else
                {
                    printf("Ошибка добавления электронного адреса.\n");
                }
                break;
            }

            case 4:     // Изменить существующую электронную почту контакта
            {
                if(new_list.size == 0) printf("Список электронных адресов пустой\n");
                else
                {   printf("Введите индекс изменяемого электронного адреса. Для отмены операции введите 0\n");
                    printf("Выбранный индекс >> ");    
                    if (scanf("%d", &number_case) != 1)
                    {
                        printf("Ошибка ввода. Нужно ввести число.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');
                    if(number_case == 0) continue;
                    if(number_case > 0 && number_case <= new_list.size )
                    {
                        printf("Изменяемый электронный адрес: %s \n", new_list.emailList[number_case-1].address);
                        printf("Введите новый  электронный адрес: ");
                        read_line(new_list.emailList[number_case-1].address, EMAIL_LEN);
                        printf("\n\nэлектронный адрес успешно изменен!\n");
                    }
                }
                break;
            }
            case 5:     // Удалить электронную почту контакта
            {
                if(new_list.size == 0) printf("Список контактов пуст\n");
                else
                {
                    printf("Введите индекс удаляемого электронного адреса. Для отмены операции введите 0\n");
                    printf("Выбранный индекс >> "); 
                    if (scanf("%d", &number_case) != 1)
                    {
                        printf("Ошибка ввода. Нужно ввести число.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');
                    if(number_case == 0) continue;
                    else
                    {
                        if(remove_emailAddress(&new_list, number_case-1))
                        {
                            printf("Электронный адрес удален успешно\n");
                        }
                        else
                        {
                            printf("Ошибка! Неудалось удалить электронный адрес\n");
                        }
                    }
                }
                break;       
            }
            default:
                printf("Неверный пункт меню.\n");
                break;
        }
    }
}

// функция редактирования  
int edit_contact_social_links(Contact *contact)
{
    if(contact == NULL ) return 0;

    SocialNetworkList new_list;
    init_social_link_list(&new_list);
    if(!copy_socialLinks(&new_list, &contact->socialLinks))
    {
        printf("Ошибка изменения списка социальных сетей контакта");
        free_social_links_list(&new_list);
        return 0;
    }                                            

    int number_case;
    while(1)
    {
        print_socialLinks_menu();   // Вывод интерфейса редактирования социальных сетей контакта

        if (scanf("%d", &number_case) != 1)
        {
            printf("Ошибка ввода. Нужно ввести число.\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        switch (number_case)
        {
            case 0:     // Отмена изменения списка социальных сетей
                free_social_links_list(&new_list);
                return 0;

            case 1:     // Сохранить изменения списка социальных сетей контакта
            {
                if(copy_socialLinks(&contact->socialLinks, &new_list))
                {
                    free_social_links_list(&new_list);
                    return 1;
                }
                else
                {
                    free_social_links_list(&new_list);
                    return 0;
                } 
            }           
            case 2:     // Вывести список социальных сетей контакта
                print_socials_list(&new_list);
                break;

            case 3:     // Добавить социальную сеть контакту
            {
                SocialNetwork temp_socialLink;

                printf("\nВведите новую социальную сеть или мессенджер: ");
                read_line(temp_socialLink.socialNetworkLink, SOCIALLINK_LEN);
            
                if(add_socialLinks(&new_list, &temp_socialLink))
                {
                    printf("Новая социальная сеть добавлена.\n");
                }
                else
                {
                    printf("Ошибка добавления новой социальной сети.\n");
                }
                break;
            }

            case 4:     // Изменить существующую социальную сеть у контакта
            {
                if(new_list.size == 0) printf("Список контактов пуст\n");
                else
                {   printf("Введите индекс изменяемой социальной сети. Для отмены операции введите 0\n");
                    printf("Выбранный индекс >> ");    
                    if (scanf("%d", &number_case) != 1)
                    {
                        printf("Ошибка ввода. Нужно ввести число.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');
                    if(number_case == 0) continue;
                    if(number_case > 0 && number_case <= new_list.size )
                    {
                        printf("Изменяемая социальная сеть: %s \n", new_list.socialLinksList[number_case-1].socialNetworkLink);
                        printf("Введите новую социальную сеть или мессенджер: ");
                        read_line(new_list.socialLinksList[number_case-1].socialNetworkLink, SOCIALLINK_LEN);
                        printf("\n\nНовая социальная сеть добавлена!\n");
                    }
                }
                break;
            }
            case 5:     // Удалить существующую социальную сеть у контакта
            {
                if(new_list.size == 0) printf("Список контактов пуст\n");
                else
                {
                    printf("Введите индекс удаляемой социальной сети. Для отмены операции введите 0\n");
                    printf("Выбранный индекс >> "); 
                    if (scanf("%d", &number_case) != 1)
                    {
                        printf("Ошибка ввода. Нужно ввести число.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');
                    if(number_case == 0) continue;
                    else
                    {
                        if(remove_socilaLink(&new_list, number_case-1))
                        {
                            printf("Социальная сеть удалена успешно\n");
                        }
                        else
                        {
                            printf("Ошибка! Неудалось удалить социальную сеть\n");
                        }
                    }
                }
                break;       
            }
            default:
                printf("Неверный пункт меню.\n");
                break;
        }
    }
}
