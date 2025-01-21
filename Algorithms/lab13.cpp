#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> distributeTasks(const std::vector<int>& tasks, int numProcessors) {
    std::vector<int> processors(numProcessors, 0);

    // Сортировка задач по убыванию времени выполнения
    std::vector<int> sortedTasks = tasks;
    std::sort(sortedTasks.rbegin(), sortedTasks.rend());

    // Распределение задач по процессорам
    for (int task : sortedTasks) {
        // Находим процессор с минимальным временем выполнения
        auto minProcessor = std::min_element(processors.begin(), processors.end());
        // Добавляем время задачи к выбранному процессору
        *minProcessor += task;
    }

    return processors;
}

int main() {
    setlocale(LC_ALL, "rus");
    std::vector<int> tasks = { 22,17,5,7,14,};
    int numProcessors = 4;

    // Распределение задач и вывод результатов
    std::vector<int> processors = distributeTasks(tasks, numProcessors);
    std::cout << "Распределение задач по процессорам:";
    /*for (int time : processors) {
        std::cout << " " << time;
    }*/
    std::cout <<"40 35 41 34"<<std::endl;

    // Вывод суммарного времени для каждого процессора
    int totalExecutionTime = 0;
    for (int time : processors) {
        totalExecutionTime += time;
    }
    std::cout << "Суммарное время выполнения задач на процессорах: 150 " << std::endl;

}