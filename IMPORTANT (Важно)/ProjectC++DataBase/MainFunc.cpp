#include <iostream>
#include <string>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "Structs.h"
#include "Prototips.h"

#pragma warning(disable : 4996)
//именно глобальные переменные
using namespace std;
//ANSI стандарт (или какой-то) предполагает рекомендацию в ЯВНОМ указании void
//Посмотри стек вызовов
//С ограничением доступа
int add_authors(){
    authors tmp; memset(&tmp, 0, sizeof(publishers));
    memset(&tmp, 0, sizeof(authors));
    bool choice = false;
    do {
        string buf;
        cout << "Добавление автора:\n";
        cout << "Name: ";
        getline(cin, buf); strcopy(tmp.name, buf);
        cout << "Otch: ";
        getline(cin, buf); strcopy(tmp.otch, buf);
        cout << "Family: ";
        getline(cin, buf); strcopy(tmp.family, buf);
        cout << "Email: ";
        getline(cin, buf); strcopy(tmp.email, buf);
        cout << "\nПовторить ввод данных Авторы - 0\n";
        cout << "Подтвердить внесение данных в БД - 1\n";
        cin >> choice;
    } while (choice != true);
    int fd; 
    open_a_w(&fd);
    if (fd < 0) {
        cout << "*************************************************************************************\n" <<
            "******                            База данных занята.                          ******\n" <<
            "*************************************************************************************\n";
        cout << "Подождите...";
        do {
            Sleep(10000);
            cout << ".\n";
            open_a_w(&fd);
        } while (fd < 0);
    }
    cout << "\nЗапись....";
    Sleep(5000);
    tmp.id = get_max_ID(fd, sizeof(authors)) + 1;
    _lseek(fd, (tmp.id - 1) * sizeof(authors), SEEK_SET);
    _write(fd, &tmp, sizeof(authors));
    _close(fd);
    cout << "\nЗапись завершена\n";
    return 1;
}
int add_publisher() {
    //Желательно придерживаться плана: 1) Создание временной структуры. 2) после заполнения и иных манипуляций открыть файл на чтение и поработать c ним 3) Закрыть файл
    //Формирование запроса и ожидание подтверждения
    publishers tmp;
    bool choice = false;
    do {
        memset(&tmp, 0, sizeof(publishers));
        string buf;
        cout << "Добавление издательства: \n";
        cout << "Name: ";
        getline(cin, buf); strcopy(tmp.name, buf);
        cout << "INN: ";
        cin >> tmp.inn;
        cout << "email: ";
        getline(cin, buf);
        getline(cin, buf);
        strcopy(tmp.email, buf);
        cout << "\nПовторить ввод данных Издательства - 0\n";
        cout << "Подтвердить внесение данных в БД - 1\n";
        cin >> choice;
    } while (choice != true);
    //Многопользовательский доступ для файла.
    int fd; 
    open_p_w(&fd);
    if (fd < 0) {
        cout << "*************************************************************************************\n" <<
            "******                            База данных занята.                          ******\n" <<
            "*************************************************************************************\n";
        cout << "Подождите...";
        do {
            Sleep(10000);
            cout << ".";
            open_p_w(&fd);
        } while (fd < 0);
    }
    cout << "\nЗапись....";
    Sleep(5000);
    tmp.id = get_max_ID(fd, sizeof(publishers)) + 1;
    _lseek(fd, (tmp.id - 1) * sizeof(publishers), SEEK_SET);
    _write(fd, &tmp, sizeof(publishers));
    _close(fd);
    cout << "\nЗапись завершена\n";
    return 1;
}
int add_data() {   
    ////////////////////////////////////////////Вводимые данные////////////////////////////////////////////////////////
    books tmp; memset(&tmp, 0, sizeof(books));
    char tmpstr[256];
    string BUF;
    int t;
    cout << "!!!Автор и Издательство должны быть учтёны в спец.столе!!!\n";
    cout << "Name of book: "; getline(cin, BUF); strcopy(tmp.name, BUF);
    cout << "Жанр (0-drama/1-comedy/2-thriller/3-adventure/4-biography)\n";
    int flag = false;
    while (flag != true) {
        cin >> t;
        if (t >= 0 && t < 5) {
            tmp.janr = static_cast<janr_t>(t);
            flag = true;
        }
    }
    cout << "Author: "; getline(cin, BUF); getline(cin, BUF); strcopy(tmpstr, BUF);
    ///////////////////////////////////Работа с содержимым authors и publishers///////////////////////////////////////////////////////
    int fd_b, fd_a, fd_p;
    open_db_r(&fd_b, &fd_a, &fd_p);
    authors buffer;
    size_t bytesRead;
    tmp.aut_id = -1;
    while ((bytesRead = _read(fd_a, &buffer, sizeof(buffer))) > 0) {
        if (bytesRead == -1)
            perror("_read");
        if (strcmp(buffer.family, tmpstr) == 0) {
            tmp.aut_id = buffer.id;
        }
    }
    memset(tmpstr, 0, sizeof(tmpstr));
    cout << "Publisher: "; getline(cin, BUF); strcopy(tmpstr, BUF);
    publishers buffer2;
    tmp.publish_id = -1;
    while ((bytesRead = _read(fd_p, &buffer2, sizeof(buffer2))) > 0) {
        if (bytesRead == -1) perror("_read");
        if (strcmp(buffer2.name, tmpstr) == 0) {
            tmp.publish_id = buffer2.id;
        }
    }
    close_db(fd_b, fd_a, fd_p);
    if (tmp.aut_id != -1 && tmp.publish_id != -1) {
        open_b_w(&fd_b);
        if (fd_b < 0) {
            cout << "*************************************************************************************\n" <<
                "******                            База данных занята.                          ******\n" <<
                "*************************************************************************************\n";
            cout << "Подождите...";
            do {
                open_b_w(&fd_b);
                Sleep(5000);
                cout << ".";
            } while (fd_b < 0);
        }
        cout << "\nЗапись....";
        Sleep(5000);
        
        _lseek(fd_b, 0, SEEK_END);
        tmp.id = get_max_ID(fd_b, sizeof(books)) + 1;
        _write(fd_b, &tmp, sizeof(tmp));
        _close(fd_b);
        cout << "\nЗапись завершена\n";
        return 1;
    }
    else { cout << "Author or Publisher not found\n"; return -1; }
}
int del_data_b() {
    int fd_b;
    open_b_r(&fd_b);
    int id;
    cout << "\nУдаление Книги";
    cout << "\nВведите ID записи: ";
    cin >> id;
    books tmp;
    bool flag = false;
    int size = get_max_ID(fd_b, sizeof(books));
    _lseek(fd_b, 0, SEEK_SET);
    for (int i = 0; i < size; i++) {
        _read(fd_b, &tmp, sizeof(tmp));
        if (tmp.id == id) {    
            cout << " Запись найдена\n.";
            _close(fd_b);
            open_b_w(&fd_b);
            if (fd_b < 0) {
                cout << "*************************************************************************************\n" <<
                    "******                            База данных занята.                          ******\n" <<
                    "*************************************************************************************\n";
                cout << "Подождите...";
                do {
                    Sleep(10000);
                    cout << ".";
                    open_b_w(&fd_b);
                } while (fd_b < 0);
            }
            
            _lseek(fd_b, i * sizeof(tmp), SEEK_SET);
            tmp.id = 0;
            write(fd_b, &tmp, sizeof(tmp));
            cout << " Записть удалена...\n";
            _close(fd_b);
            flag = true;
            break;
        }
    }
    if (id > size || flag == false ) {
        cout << "Запись с таким ID не найдена";
        return -1;
    }
    return 1;
} //Удаление подразумевает лишь затирание ид
int kaskad_del(){
    cout << "Каскадное удаление Книг(и)\n";
    cout << "Введите Фамилию Автора и Издательства через пробел\n";
    string str;
    char buf1[24]; char buf2[24];   
    getline(cin, str); strcopy(buf1, str);
    char* _src = &str[0]; char* _dest = &buf1[0];
    /////////////////////////////////////////////////////////////////////////////
    while (*_src != ' ') {
        *_dest = *_src;
        _src++;
        _dest++;
    }
    _src++;
    _dest = &buf2[0];
    while (*_src != ' ' || *_src != '\0') {
        *_dest = *_src;
        _src++;
        _dest++;
    }
    /////////////////////////////////////////////////////////////////////////////
    int fd_b, fd_a, fd_p;
    open_db_r(&fd_b, &fd_a, &fd_p);

    books tmpB;
    books tmpA;
    books tmpP;
    int sizeB = get_max_ID(fd_b, sizeof(tmpB));
    int sizeA = get_max_ID(fd_a, sizeof(tmpA));
    int sizeP = get_max_ID(fd_p, sizeof(tmpP));
    _lseek(fd_b, 0, SEEK_SET);
    for (int i = 0; i < sizeB; i++) {
        _read(fd_b, &tmpB, sizeof(tmpB));
        for()
    }
}
int edit_data_b() {
    cout << "Введите ID для редактирования" << "   ";
    int id; cin >> id;
    books buf;
    string buffer;
    bool flag = false;
    int fd_b; 
    open_b_r(&fd_b);
    int size = get_max_ID(fd_b, sizeof(buf));
    _lseek(fd_b, 0, SEEK_SET);
    for (int i = 0; i < size; i++) {
        _read(fd_b, &buf, sizeof(buf));
        if (buf.id == id && buf.id != 0) {
            int choice;
            do {
                cout << "Введите данные для редактирования:";
                cout << "\n Name:";
                getline(cin, buffer);  getline(cin, buffer); if (buffer.length()) strcopy(buf.name, buffer);
                cout << "Janr (0-drama/1-comedy/2-thriller/3-adventure/4-biography):";
                int tmp; cin >> tmp;
                buf.janr = static_cast<janr_t>(tmp); //??
                _close(fd_b);
                cout << "Подтвердить изменение данных - 1";
                cout << "Внести повторно текущие данные - 2";
                cout << "Отменить и выйти в главное меню - 0";
                cout << "\nВаш выбор -> ";
                cin >> choice;
                if (choice == 0)
                    return -1;
            } while (choice != 1);

            open_b_w(&fd_b);
            if (fd_b < 0) {
                cout << "*************************************************************************************\n" <<
                    "******                            База данных занята.                          ******\n" <<
                    "*************************************************************************************\n";
                cout << "Подождите...";
                do {
                    Sleep(10000);
                    cout << ".";
                    open_b_w(&fd_b);
                } while (fd_b < 0);
            }
            cout << "\nЗапись....";
            Sleep(5000);
            _lseek(fd_b, i * sizeof(books), SEEK_SET);
            write(fd_b, &buf, sizeof(buf));
            _close(fd_b);
            flag = true;
            cout << "\nЗапись завершена\n";
            return 1;
        }
    }
    _close(fd_b);
    if (flag == false || id > size) {
        cout << "Введённый ID не существует";
        return -1;
    }
}
int edit_data_a() {
    cout << "Введите ID для редактирования" << "   ";
    int id; cin >> id;
    authors buf;
    bool flag = false;
    int fd_a;
    open_b_r(&fd_a);
    int size = get_max_ID(fd_a, sizeof(buf));
    _lseek(fd_a, 0, SEEK_SET);
    for (int i = 0; i < size; i++) {
        _read(fd_a, &buf, sizeof(buf));
        if (buf.id == id && buf.id != 0) {
            int choice;
            do {
                string buffer;
                cout << "Введите данные для редактирования:";
                cout << "\n Name: ";
                getline(cin, buffer); if (buffer.length()) strcopy(buf.name, buffer);
                cout << "Family: ";
                getline(cin, buffer); if (buffer.length()) strcopy(buf.family, buffer);
                cout << "Otch: ";             //???
                getline(cin, buffer); if (buffer.length()) strcopy(buf.otch, buffer);
                cout << "Email: ";
                getline(cin, buffer); if (buffer.length()) strcopy(buf.email, buffer);
                _close(fd_a);
                cout << "Подтвердить изменение данных - 1";
                cout << "Внести повторно текущие данные - 2";
                cout << "Отменить и выйти в главное меню - 0";
                cout << "\nВаш выбор -> ";
                cin >> choice;               
                if (choice == 0)
                    return -1;
            } while (choice != 1);
            open_b_w(&fd_a);
            if (fd_a < 0) {
                cout << "*************************************************************************************\n" <<
                    "******                            База данных занята.                          ******\n" <<
                    "*************************************************************************************\n";
                cout << "Подождите...";
                do {
                    Sleep(10000);
                    cout << ".";
                    open_b_w(&fd_a);
                } while (fd_a < 0);
            }
            cout << "\nЗапись....";
            Sleep(5000);
            cout << "\nЗапись завершена\n";
            _lseek(fd_a, i * sizeof(books), SEEK_SET);
            write(fd_a, &buf, sizeof(buf));
            _close(fd_a);
            flag = true;
            return 1;
        }
    }
    _close(fd_a);
    if (flag == false || id > size) {
        cout << "Введённый ID не существует";
        return -1;
    }
}
int edit_data_p() {
    cout << "Введите ID для редактирования" << "   ";
    int id; cin >> id;
    publishers buf;
    bool flag = false;
    int fd_p;
    open_b_r(&fd_p);
    int size = get_max_ID(fd_p, sizeof(buf));
    _lseek(fd_p, 0, SEEK_SET);
    for (int i = 0; i < size; i++) {
        _read(fd_p, &buf, sizeof(buf));
        if (buf.id == id && buf.id != 0) {
            int choice;
            string buffer;
            do {
                cout << "Введите данные для редактирования:";
                cout << "\n Name: ";
                getline(cin, buffer); getline(cin, buffer); if (buffer.length()) strcopy(buf.name, buffer);
                cout << "\nINN: ";
                cin >> buf.inn;
                cout << "\nEmail: ";
                getline(cin, buffer); if (buffer.length()) strcopy(buf.email, buffer);
                _close(fd_p);
                cout << "Подтвердить изменение данных - 1";
                cout << "Внести повторно текущие данные - 2";
                cout << "Отменить и выйти в главное меню - 0";
                cout << "\nВаш выбор -> ";
                cin >> choice;
                if (choice == 0)
                    return -1;             
            } while (choice != 1);

            open_b_w(&fd_p);
            if (fd_p < 0) {
                cout << "*************************************************************************************\n" <<
                    "******                            База данных занята.                          ******\n" <<
                    "*************************************************************************************\n";
                cout << "Подождите...";
                do {
                    Sleep(10000);
                    cout << ".";
                    open_b_w(&fd_p);
                } while (fd_p < 0);
            }
            cout << "\nЗапись....";
            Sleep(5000);
            cout << "\nЗапись завершена\n";
            _lseek(fd_p, i * sizeof(books), SEEK_SET);
            write(fd_p, &buf, sizeof(buf));
            _close(fd_p);
            flag = true;
            return 1;
        }
    }
    _close(fd_p);
    if (flag == false || id > size) {
        cout << "Введённый ID не существует";
        return -1;
    }
}
//Без ограничений доступа
void search_data() {
    cout << "Введите искомую запись -> ";
    string BUF;
    getline(cin, BUF);
    BUF = setlow(BUF);
    int fd_b = 0, fd_a = 0, fd_p = 0;
    open_db_r(&fd_b, &fd_a, &fd_p);
    books tmp; authors tmp1; publishers tmp2;
    int size = get_max_ID(fd_b, sizeof(tmp));
    _lseek(fd_b, 0, SEEK_SET);
    for (int i = 0; i < size; i++) {
        _read(fd_b, &tmp, sizeof(tmp));
        if (tmp.id != 0) {            
            string name = setlow(tmp.name);
            if (name.find(BUF) != string::npos) {
                cout << "\n||| Книги |||" << "   ";
                cout << "\n Name: " << tmp1.name << "   ";
            }
        }
    }
    _close(fd_b);

    size = get_max_ID(fd_a, sizeof(tmp1));
    _lseek(fd_a, 0, SEEK_SET);
    for (int i = 0; i < size; i++) {
        if (tmp.id != 0) {
            _read(fd_a, &tmp1, sizeof(tmp1));
            string name = setlow(tmp1.name); string otch = setlow(tmp1.otch);string family = setlow(tmp1.family); string email = setlow(tmp1.email);
            if (name.find(BUF) != string::npos || otch.find(BUF) != string::npos || family.find(BUF) != string::npos || email.find(BUF) != string::npos) {
                cout << "\n||| Авторы |||" << "   ";
                cout << "\nID: " << tmp1.id << "   ";
                cout << "\n Name: " << tmp1.name << "   ";
                cout << "\n Otch: " << tmp1.otch << "   ";
                cout << "\n Family: " << tmp1.family << "   ";
                cout << "\n mail: " << tmp1.email << "   ";
            }
        }
    }
    _close(fd_a);

    size = get_max_ID(fd_p, sizeof(tmp2));
    _lseek(fd_p, 0, SEEK_SET);
    for (int i = 0; i < size; i++) {
        if (tmp.id != 0) {
            _read(fd_p, &tmp2, sizeof(tmp2));
            string name = setlow(tmp2.name);
            int inn = tmp2.inn;
            string email = setlow(tmp2.email);
            if (name.find(BUF) != string::npos || email.find(BUF) != string::npos) {
                cout << "\n||| Издательства |||" << "   ";
                cout << "\nID: " << tmp2.id << "   ";
                cout << "\n Name: " << tmp2.name << "   ";
                cout << "\n INN: " << tmp2.inn << "   ";
                cout << "\n mail: " << tmp2.email << "   ";
            }
        }
    }
    close(fd_p);
}
void print_data_B() {
    int fd_b, fd_a, fd_p;
    open_db_r(&fd_b, &fd_a, &fd_p);
    books tmp;
   // _lseek(fd_b, 0, SEEK_SET); тут не нужен, т.к изначально при открытии файла он уже на начале
    int N = get_max_ID(fd_b, sizeof(books)); _lseek(fd_b, 0, SEEK_SET);
    for (int i = 0; i < N; i++) {
        _read(fd_b, &tmp, sizeof(tmp));
        if (tmp.id != 0) {
            cout << "\nID: " << tmp.id << "   ";
            cout << "\n Name: " << tmp.name << "   ";
            cout << "\n Genre: ";
            switch (tmp.janr) {
            case 0: cout << "Drama" << "   "; break;
            case 1: cout << "Comedy" << "   "; break;
            case 2: cout << "Thriller" << "   "; break;
            case 3: cout << "Adventure" << "   "; break;
            case 4: cout << "Biography" << "   "; break;
            default:cout << "Error";}
            int size = get_max_ID(fd_a, sizeof(authors)); _lseek(fd_a, 0, SEEK_SET);
            authors buffer;
            for (int i = 0; i < size; i++) {
                read(fd_a, &buffer, sizeof(buffer));
                if (buffer.id == tmp.aut_id) {
                    cout << "\n Author: " << buffer.family;
                    break;
                }
            }
            _close(fd_a);

            size = get_max_ID(fd_p, sizeof(publishers)); _lseek(fd_p, 0, SEEK_SET);//вернул на исходную
            publishers buffer2;
            for (int i = 0; i < size; i++) {
                _read(fd_p, &buffer2, sizeof(buffer2));
                if (buffer2.id == tmp.publish_id) {
                    cout << "\n Publisher: " << buffer2.name;
                    break;
                }
            }
            _close(fd_p);
        }       
    }
    _close(fd_b);
}
void print_data_A() {
    int fd_a;
    open_a_r(&fd_a);        
    authors buf;
    int size = get_max_ID(fd_a, sizeof(authors));  
    _lseek(fd_a, 0, SEEK_SET);
    for (int i = 0; i < size; i++) {
        _read(fd_a, &buf, sizeof(buf));
        if (buf.id != 0) {
            cout << "\nID: " << buf.id << "   ";
            cout << "\n Name: " << buf.name << "   ";
            cout << "\n Otch: " << buf.otch << "   ";
            cout << "\n Family: " << buf.family << "   ";
            cout << "\n mail: " << buf.email << "   ";
        }
    }
}
void print_data_P() {
    int fd_p;
    open_p_r(&fd_p);
    publishers buf;
    int size = get_max_ID(fd_p, sizeof(publishers)); _lseek(fd_p, 0, SEEK_SET);  
    for (int i = 0; i < size; i++) {
        _read(fd_p, &buf, sizeof(buf));
        if (buf.id != 0) {
            cout << "\nID: " << buf.id << "   ";
            cout << "\n Name: " << buf.name << "   ";
            cout << "\n INN: " << buf.inn << "   ";
            cout << "\n mail: " << buf.email << "   ";
        }
    }
    _close(fd_p);
}
void quit() {
    exit(0); // что-то должен вернуть
}
//Вспомогательные
void tolowerPtr(char* p)
{
    switch (*p)
    {
    case 'А':*p = 'а'; return;
    case 'Б':*p = 'б'; return;
    case 'В':*p = 'в'; return;
    case 'Г':*p = 'г'; return;
    case 'Д':*p = 'д'; return;
    case 'Е':*p = 'е'; return;
    case 'Ё':*p = 'ё'; return;
    case 'Ж':*p = 'ж'; return;
    case 'З':*p = 'з'; return;
    case 'И':*p = 'и'; return;
    case 'Й':*p = 'й'; return;
    case 'К':*p = 'к'; return;
    case 'Л':*p = 'л'; return;
    case 'М':*p = 'м'; return;
    case 'Н':*p = 'н'; return;
    case 'О':*p = 'о'; return;
    case 'П':*p = 'п'; return;
    case 'Р':*p = 'р'; return;
    case 'С':*p = 'с'; return;
    case 'Т':*p = 'т'; return;
    case 'У':*p = 'у'; return;
    case 'Ф':*p = 'ф'; return;
    case 'Х':*p = 'х'; return;
    case 'Ц':*p = 'ц'; return;
    case 'Ч':*p = 'ч'; return;
    case 'Ш':*p = 'ш'; return;
    case 'Щ':*p = 'щ'; return;
    case 'Ъ':*p = 'ъ'; return;
    case 'Ы':*p = 'ы'; return;
    case 'Ь':*p = 'ь'; return;
    case 'Э':*p = 'э'; return;
    case 'Ю':*p = 'ю'; return;
    case 'Я':*p = 'я'; return;

    case 'A':*p = 'a'; return;
    case 'B':*p = 'b'; return;
    case 'C':*p = 'c'; return;
    case 'D':*p = 'd'; return;
    case 'E':*p = 'e'; return;
    case 'F':*p = 'f'; return;
    case 'G':*p = 'g'; return;
    case 'H':*p = 'h'; return;
    case 'I':*p = 'i'; return;
    case 'J':*p = 'j'; return;
    case 'K':*p = 'k'; return;
    case 'L':*p = 'l'; return;
    case 'M':*p = 'm'; return;
    case 'N':*p = 'n'; return;
    case 'O':*p = 'o'; return;
    case 'P':*p = 'p'; return;
    case 'Q':*p = 'q'; return;
    case 'R':*p = 'r'; return;
    case 'S':*p = 's'; return;
    case 'T':*p = 't'; return;
    case 'U':*p = 'u'; return;
    case 'V':*p = 'v'; return;
    case 'W':*p = 'w'; return;
    case 'X':*p = 'x'; return;
    case 'Y':*p = 'y'; return;
    case 'Z':*p = 'z'; return;
    };
    return;
}
string setlow(string buf) {
    char* c = const_cast<char*>(buf.c_str());
    size_t l = buf.size();
    for (char* c2 = c; c2 < c + l; c2++) tolowerPtr(c2);
    return buf;
}
void strcopy(char* str, string buf) {
    char* p = str;
    char* i = &buf[0];
    while (*p++ = *i++);
}
inline long get_max_ID(int fd, size_t sizeStruct) {
    return _lseek(fd, 0, SEEK_END) / sizeStruct; //sizeof директива компилятора, он присваивает значение во время выполнения и НИЧЕГО НЕ ВЫЧИСЛЯЕТ, централизвоать/унифицирвоать не получится.
}