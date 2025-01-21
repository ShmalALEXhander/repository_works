using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
class Program
{
    static void Main()
    {
        while (true)
        {
            NumberCollection collection = new NumberCollection();
            Console.WriteLine("Введите последовательность любых чисел");
            string input = Console.ReadLine();
            string[] massSTR = input.Split(' ');
            foreach (string s in massSTR)
            {
                if (double.TryParse(s, out double number))
                {
                    collection.Add(number);
                }
            }
            double[] mass = collection.ToArray();
            Array.Sort(mass);
            Array.Reverse(mass);

            foreach (double number in mass)
            {
                Console.Write($"{number} ");
            }
            Console.WriteLine(" ");
        }
    } // генетор Фибоначи, генератор факториала разбери, генератол простых чисел
    // Иммет смысл создавать класс, описывающий или реализующий ещё не реализованнную в ЯП
    // структуру, наборы данных. Для стандратных структур оборачивать будет излишне.
    public class NumberCollection : IEnumerable<double>
    {
        public HashSet<double> num = new HashSet<double>();

        public void Add(double number)
        {
            num.Add(number);
        }
        public double[] ToArray()
        {
            double[] array = new double[num.Count];
            num.CopyTo(array);
            return array;
        }
        public IEnumerator<double> GetEnumerator()// перечислитель
        {
            return num.GetEnumerator();
        }
        IEnumerator IEnumerable.GetEnumerator() // Это переопределение
        {
            return GetEnumerator(); // Теперь интерфейс вызывает метод из number collection
        }
    }
}