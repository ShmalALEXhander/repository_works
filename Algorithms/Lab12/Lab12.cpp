#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
// Функция для нахождения максимального значения среди сумм элементов подмножеств
int findMaxSum(const std::vector<std::vector<int>>& subsets) {
    int maxSum = 0;
    for (const auto& subset : subsets) {
        int sum = std::accumulate(subset.begin(), subset.end(), 0);
        maxSum = std::max(maxSum, sum);
    }
    return maxSum;
}

// Функция для разбиения вектора задач на подмножества для процессоров
std::vector<std::vector<int>> distributeTasks(const std::vector<int>& tasks, int processors) {
    int n = tasks.size();
    int subsetSize = (n + processors - 1) / processors; // Размер подмножества

    std::vector<std::vector<int>> subsets(processors);
    for (int i = 0; i < processors; ++i) {
        int start = i * subsetSize;
        int end = std::min(start + subsetSize, n);
        subsets[i].assign(tasks.begin() + start, tasks.begin() + end);
    }

    return subsets;
}

int main() {
    setlocale(LC_ALL, "rus");
    // Вектор задач T
    std::vector<int> T = { 22, 17, 5, 7, 14, 13 , 12, 11, 10, 3 , 4, 12 , 11, 5 ,4};
    // Количество процессоров
    int processors = 4;

    // Сортировка вектора задач по убыванию
    std::sort(T.rbegin(), T.rend());

    // Распределение задач по процессорам
    std::vector<std::vector<int>> subsets = distributeTasks(T, processors);

    // Находим максимальное время выполнения среди всех процессоров
    int maxTime = findMaxSum(subsets);

    // Вывод результатов
    std::cout << "Распределение задач по " << processors << " процессорам:" << std::endl;
    for (int i = 0; i < processors; ++i) {
        std::cout << "Процессор " << i + 1 << ": ";
        for (int task : subsets[i]) {
            std::cout << task << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Максимальное время выполнения: " << maxTime << std::endl;

    return 0;
}