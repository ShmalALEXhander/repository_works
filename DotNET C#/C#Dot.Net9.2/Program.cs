using System;
using System.Collections.Generic;
using System.Threading;
using System.Diagnostics;
using System.Runtime.Intrinsics;

class Program
{
    class Multiply
    {
        const int N = 20000;
        double[,] matrix = new double[N, N];
        double[,] matrix2 = new double[N, N];
        double[] vector = new double[N];
        double[] vector2 = new double[N];

        public Multiply()
        {
            Random rnd = new Random();
            for (int i = 0; i < N; i++)
            {
                vector[i] = rnd.NextDouble() % 5000;
                for (int j = 0; j < N; j++)
                    matrix[i, j] = rnd.NextDouble() % 5000;
            }
            for (int i = 0; i < N; i++)
            {
                vector2[i] = vector[i];
                for (int j = 0; j < N; j++)
                {
                    matrix2[i, j] = matrix[i, j];
                }
            }
        }
        private void MultiplyPart(int startRow, int endRow, double[,] result)
        {         
            for (int i = startRow; i < endRow; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    result[i, j] += vector[j] * matrix[i, j];
                }
            }
        }
        public void MultOne(int num)
        {
            Stopwatch sw = new Stopwatch();
            double[,] result = new double[N, N];
            sw.Start();
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {   
                    result[i, j] += vector2[j] * matrix2[i, j];
                }
            }
            sw.Stop();
            Console.WriteLine(sw.ElapsedMilliseconds);
        }
        public void MultMany(int num)
        {
            Stopwatch sw = new Stopwatch();
            double[,] result = new double[N, N];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    result[i, j] = 0;

            int part = N / num;
            Thread[] threads = new Thread[num];

            sw.Start();

            for (int t = 0; t < num; t++)
            {
                int startRow = t * part;
                int endRow = (t == num - 1) ? N : startRow + part;
                threads[t] = new Thread(() => MultiplyPart(startRow, endRow, result));
                threads[t].Start();
            }
            for (int t = 0; t < num; t++)
            {
                threads[t].Join();
            }
            sw.Stop();          
            Console.WriteLine(sw.ElapsedMilliseconds);
        }
    }
    static void Main()
    {
        int numThreads = 8;
        Multiply object1 = new Multiply();
        Console.WriteLine($"MultMany: ");
        object1.MultMany(numThreads);
        Console.WriteLine($"MultOne : ");
        object1.MultOne(numThreads);
        //Только треды, больше ничего для выполнения задачи не требуется
    }
}
//sw.Start();
//for (int i = 0; i < N; i++)
//{
//    for (int j = 0; j < N; j++)
//    {
//        result[i, j] += vector[j] * matrix[i, j];
//    }
//}
//sw.Stop();
//Console.WriteLine(sw.ElapsedMilliseconds);