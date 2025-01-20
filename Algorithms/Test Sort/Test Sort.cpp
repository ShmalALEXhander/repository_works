#include <iostream>
using namespace std;
int main()
{
    int size = 10;
    int *massiv = new int[size];
    for (int i = 0; i < size; i++) {
        massiv[i] = rand() % 50;
    }
    for (int i = 0; i < size; i++) {
        cout << massiv[i]<<" ";
    }
    for (int i = 1; i < size; i++)
    {
        int value = massiv[i]; 
        int index = i; 
        while ((index > 0) && (massiv[index - 1] > value))
        { 
            massiv[index] = massiv[index - 1];
            index--;    
        }
        massiv[index] = value; 
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << massiv[i]<<" ";
    }
}