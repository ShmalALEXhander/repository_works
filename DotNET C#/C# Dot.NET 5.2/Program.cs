using System;
using System.Collections;
using System.Collections.Generic;
class Program
{
    public class Fibonchi : IEnumerable
    {
        private int d1, d2, d3;
        private List<int> fibNum;
        public Fibonchi(int a, int b) {
            d1 = a;
            d2 = b;
            fibNum = new List<int>() { d1, d2 };
        }
        public void fib(int x)
        {
            if (x == 0) Console.Write($"{x}");
            else if (x == 1) Console.Write($"{x - 1} {x}");
            else
            {
                Console.Write("0 1 ");
                for (int i = 2; i < x; i++)
                {
                    Console.Write($"{d3 = d1 + d2} ");
                    fibNum.Add(d3);
                    d1 = d2;
                    d2 = d3;
                }
            }
            Console.WriteLine();
        }


        //Интерфейсы
        public IEnumerator<int> GetEnumerator()
        {
            yield return d1;
            yield return d2;
            //foreach (var number in _fibonacciNumbers)
            //{
            //    yield return number;
            //}

            while (true)
            {
                int next = d1 + d2;
                yield return next;
                d1 = d2;
                d2 = next;
            }
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
    static void Main()
    {
        Fibonchi fib = new Fibonchi(0, 1);
        Fibonchi fib1 = new Fibonchi(0, 1);
        Console.WriteLine("Последовательность фибоначи");
        fib.fib(13);
        Console.WriteLine("Итерация через IEnumerable:");
        foreach (var number in fib1)
        {
            if (number >= 145) break; // Прерываем итерацию, если число больше 100
            Console.Write(number + " ");
        }
        // Прикол в том что у меня последовательно не сохраняется между шагами...
    } 
}