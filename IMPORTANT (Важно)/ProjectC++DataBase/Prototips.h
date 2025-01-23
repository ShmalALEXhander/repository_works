#pragma once
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <iomanip>
using namespace std;

//Работа с файла в бинарном файле
int open_b_r(int*);
int open_a_r(int*);
int open_p_r(int*);
int open_p_w(int*);
int open_a_w(int*);
int open_b_w(int*);
int open_db_r(int*, int*, int*);
int open_db_w(int*, int*, int*);
int close_db(int, int, int);
//Основные функции
int add_authors();
int add_publisher();
int add_data();   
int edit_data_b();
int del_data_b();
int kaskad_del();
void print_data_B();
void print_data_A();
void print_data_P();
void quit();
void search_data();
void menu(void);
//Вспомогательные функции
void tolowerPtr(char*);
string setlow(string);
void strcopy(char*, string);
inline long get_max_ID(int, size_t);
