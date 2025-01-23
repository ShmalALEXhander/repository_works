#include<iostream>
#include<windows.h>
#include"Prototips.h"
#include"Structs.h"
using namespace std;

void menu(void) { // Запись это есть объект. Объектом не должна быть БАЗА.
    int ans;
    int flag;
    do {
        flag = 0;
        cout << "\n\nВыберите функцию: \n";
        cout << "1 - Вывести информацию об Книгах\n";
        cout << "2 - Вывести информацию об Авторах\n";
        cout << "3 - Вывести информацию об Издательствах\n";
        cout << "4 - Поиск записи\n";
        cout << "5 - Добавить Автора\n";
        cout << "6 - Добавить Издательство\n";
        cout << "7 - Добавление Книги\n"; // Найти автора и издательство            
        cout << "8 - Редактирование данных Книги\n";
        cout << "9 - Удаление Книги\n";
        cout << "10 - Каскадное удаление Автора/Издательства\n";
        cout << "0 - Выход\n";
        cout << "--> ";
        cin.clear();
        cin >> ans;
        getchar();
        system("cls");
        switch (ans) {
        case 1: print_data_B(); break; //Чтение
        case 2: print_data_A(); break; //Чтение
        case 3: print_data_P(); break; //Чтение
        case 4: search_data(); break; // Чтение
        case 5: add_authors(); break; // Чтение
        case 6: add_publisher(); break; // Чтение
        case 7: add_data(); break;// Чтение + Запись    
        case 8: edit_data_b(); break; // Чтение + ЗАпись
        case 9: del_data_b(); break;  // Чтение + запись            
        case 10: kaskad_del(); break;  // Чтение + запись            
        case 0: quit(); //Ничего
        default:
            printf("Неправильный выбор\n");
            flag = 1;
            break;
        } // Роли выполняй только в меню
    } while (flag == 1);
}
int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    while (1) menu();
}