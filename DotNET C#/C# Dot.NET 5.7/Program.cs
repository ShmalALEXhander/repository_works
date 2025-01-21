using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;
//Из заданной строки сформировать последовательность 
//уникальных чисел содержащихся в строке отсортировав их в 
//порядке убывания.
class Program{
    static void Main(){
        HashSet<double> massTMP = new HashSet<double>();
        Console.WriteLine("Введите последовательность чисел");
        string str = Console.ReadLine();          
        
        string[] massSTR = str.Split(' ');
        foreach (string numStr in massSTR){
            if(double.TryParse(numStr, out double number)){
                massTMP.Add(number);
            }
        }

        double[] mass = new double[massTMP.Count];
        massTMP.CopyTo(mass);
        Array.Sort(mass); // Array применим к массивам
        Array.Reverse(mass);
        
        foreach(double number in mass){
            Console.Write($"{number} ");
        }
    }
}
//В данной реализации можно использовать структуру SortedSet(аналог по синтаксису)
//для HashSET. SortedSet может с помощью выражений поменять порядок сортировки (реверс)
//List<double> sortedList = uniqueNumbers.ToList();
//sortedList.Sort((a, b) => b.CompareTo(a)); // Сортировка по убыванию