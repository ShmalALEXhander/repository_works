using System;
using System.ComponentModel.DataAnnotations;
using System.Drawing;

class Program
{
    static void Main()
    {
        int i, j;
        double[] massX = { 5, 1, 4, 3, 8, 2, 3 };
        double[] massY = { 2, 3, 6, 2, 6, 4, 9 }; // Работа с парами, хранящиеся в двух массивах по 1 индексу
        // Тут обработка исключения
        int size = massX.Length;
        double real;
        double imag;
        double maxLength = 0;
        (int index1, int index2) bestPair = (-1, -1); // Определяется тип, парный, который содержит 2 поля
        // В С# в коллекциях есть тип Pair из Коллекций.

        for (i = 0; i < size; i++){
            for (j = 0; j < size; j++){
                if (i == j)
                    continue;
                real = massX[i] * massX[j] - massY[i] * massY[j]; //-30
                imag = massX[i] * massY[j] + massY[i] * massX[j];
                double length = Math.Sqrt(real * real + imag * imag);
                //Проверка max длины.
                if (length > maxLength){
                    maxLength = length;
                    bestPair = (i, j);
                }
            }
        }
        if (bestPair.index1 != -1 && bestPair.index2 != -1){
            Console.WriteLine($"Пара векторов с наибольшей длиной : {bestPair.index1} и {bestPair.index2} ");
            Console.WriteLine($"Длина произведения : {maxLength}");
        }
        else Console.WriteLine("Не найдены векторы."); // тогда и только тогда когда  массивы координат незаполнены
    }
}