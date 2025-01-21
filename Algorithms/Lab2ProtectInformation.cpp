
#include <iostream>
#include <vector>
#include <cstdlib> // Для использования функции rand()

// Константы для определения типов доступа
const int NO_ACCESS = 0;
const int READ_ACCESS = 1;
const int WRITE_ACCESS = 2;
const int ADMIN_ACCESS = 7;

int main() {
    // Задаем количество субъектов и объектов
    int numSubjects = 3; // Замените на значение из вашего варианта
    int numObjects = 4; // Замените на значение из вашего варианта

    // Создаем матрицу доступов
    std::vector<std::vector<int>> accessMatrix(numSubjects, std::vector<int>(numObjects));

    // Заполняем матрицу доступов случайными значениями
    for (int i = 0; i < numSubjects; ++i) {
        for (int j = 0; j < numObjects; ++j) {
            if (i == 0) {
                accessMatrix[i][j] = ADMIN_ACCESS; // Первый субъект - администратор
            }
            else {
                accessMatrix[i][j] = rand() % 8; // Генерируем случайные значения от 0 до 7
            }
        }
    }

    // Выводим матрицу доступов
    for (int i = 0; i < numSubjects; ++i) {
        for (int j = 0; j < numObjects; ++j) {
            std::cout << accessMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}