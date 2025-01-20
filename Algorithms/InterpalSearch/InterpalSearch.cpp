#include <iostream>
using namespace std;
const int N = 7;
//интерполяционный поиск
int InterpolSearch(int *A, int key){
	int mid, left = 0, right = N - 1;
	while (A[left] <= key && A[right] >= key){
		mid = left + ((key - A[left]) * (right - left)) / (A[right] - A[left]);
		if (A[mid] < key) left = mid + 1;
		else if (A[mid] > key) right = mid - 1;
		else return mid;
	}
	if (A[left] == key) return left;
	else return -1;
}
//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	int i, key;
	int A[] = { 1,2,4,5,6,8,9 };
	cout << "Искомый элемент -> "; cin >> key; //ввод ключа
	cout << "Исходный массив: ";
	for (i = 0; i < N; i++) cout << A[i] << " "; //вывод массива
	int tmp = InterpolSearch(A, key);
	if (tmp == -1) cout << "\nЭлемент не найден";
	else cout << "\nНомер элемента: " << tmp + 1;
	system("pause>>void");
}