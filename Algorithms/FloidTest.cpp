﻿#include <iostream>
using namespace std;
const int N= 4;

int main()
{
    setlocale(LC_ALL, "rus");
    int i, j;
    int matrix[N][N]{
        {0,2,5,7},
        {4,0,999,5},
        {2,999,0,3},
        {999,6,3,0},
    };
    cout << "Матрица достижимости(изначальная):\n";
    for (i = 0; i < N; i++) {
        cout << "\n";
        for (j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////
    //               АЛГОРИТМ МЕЖДУ СЛЭШАМИ
    int F[N][N];
    for (i = 0; i < N; i++) //Исходная матрица значений показывающих по столбцам номер вершины из которой производится вход в вершину соответствующему данному столбцу
        for (j = 0; j < N; j++) {
            F[i][j] = i; //Почему именно так формируем???? - начальное состояние графа. Эта матрица нужна для просмотра замен (визуализация), нужна в кратчайших путях.
        } //Инициализация матрицы путей(НЕМИНИМАЛЬНЫХ) (нужна ли она в неполном графе?)
    int k;
    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    F[i][j] = F[k][j];           // F[i][k] - конечный путь до вершины
                }
            }
    ////////////////////////////////////////////////////////////////////////////////////
    cout << "Матрица достижимости:\n";
    for (i = 0; i < N; i++) { //Матрица кратчайших расстояний между всеми вершинами сразу
        cout << "\n";
        for (j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
    }
    
  /*  cout << "\nМатрица путей (минимальных):\n";
    for (i = 0; i < N; i++) {
        cout << "\n";
        for (j = 0; j < N; j++) {
            cout << F[i][j] << " ";
        }
    }*/
}
        