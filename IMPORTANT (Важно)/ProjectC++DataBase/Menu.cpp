#include<iostream>
#include<windows.h>
#include"Prototips.h"
#include"Structs.h"
using namespace std;

void menu(void) { // ������ ��� ���� ������. �������� �� ������ ���� ����.
    int ans;
    int flag;
    do {
        flag = 0;
        cout << "\n\n�������� �������: \n";
        cout << "1 - ������� ���������� �� ������\n";
        cout << "2 - ������� ���������� �� �������\n";
        cout << "3 - ������� ���������� �� �������������\n";
        cout << "4 - ����� ������\n";
        cout << "5 - �������� ������\n";
        cout << "6 - �������� ������������\n";
        cout << "7 - ���������� �����\n"; // ����� ������ � ������������            
        cout << "8 - �������������� ������ �����\n";
        cout << "9 - �������� �����\n";
        cout << "10 - ��������� �������� ������/������������\n";
        cout << "0 - �����\n";
        cout << "--> ";
        cin.clear();
        cin >> ans;
        getchar();
        system("cls");
        switch (ans) {
        case 1: print_data_B(); break; //������
        case 2: print_data_A(); break; //������
        case 3: print_data_P(); break; //������
        case 4: search_data(); break; // ������
        case 5: add_authors(); break; // ������
        case 6: add_publisher(); break; // ������
        case 7: add_data(); break;// ������ + ������    
        case 8: edit_data_b(); break; // ������ + ������
        case 9: del_data_b(); break;  // ������ + ������            
        case 10: kaskad_del(); break;  // ������ + ������            
        case 0: quit(); //������
        default:
            printf("������������ �����\n");
            flag = 1;
            break;
        } // ���� �������� ������ � ����
    } while (flag == 1);
}
int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    while (1) menu();
}