using System;
using System.Diagnostics;
using System.Numerics;
using System.Threading;
class Program
{
    public class Mult
    {
        const int N = 20000;
        double[,] matrix1 = new double[N, N];
        double[,] matrix2 = new double[N, N];
        double[] vector1 = new double[N];
        double[] vector2 = new double[N];
        public Mult()
        {
            Random rnd = new Random();
            for (int i = 0; i < N; i++)
            {
                vector1[i] = rnd.NextDouble() % 5000;
                vector2[i] = vector1[i];
                for (int j = 0; j < N; j++)
                {
                    matrix1[i, j] = rnd.NextDouble() % 5000;
                    matrix2[i, j] = matrix1[i, j];
                }
            }
        }
        public void MultOne(int num) // Кол-во ядер
        {
            Stopwatch sw = new Stopwatch();
            sw.Start();
            double[,] result = new double[N, N];
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    result[i, j] += vector2[j] * matrix2[i,j];
                }
            }
            sw.Stop();
            Console.WriteLine(sw.ElapsedMilliseconds);
        }
        public void MultMany(int num) // Кол-во ядер
        {
            Stopwatch sw = new Stopwatch();
            double[,] result = new double[N,N];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    result[i, j] = 0;
            int part = N / num;
            Thread[] threads = new Thread[num];

            sw.Start();

            for (int i = 0; i < num; i++)
            {
                int startRow = i * part;
                int endRow = startRow + part;
                threads[i] = new Thread(() => MultiplyPart(startRow, endRow, result));
                threads[i].Start();
            }
            for (int i = 0; i < num; i++)
            {
                threads[i].Join();
            }
            sw.Stop();
            Console.WriteLine(sw.ElapsedMilliseconds);
        }
        private void MultiplyPart(int startRow, int endRow, double[,] result)
        {          
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    result[i, j] += vector2[j] * matrix2[i, j];
                }
            }
        }
    }
    static void Main()
    {
        int numThreads = 8;
        Mult object1 = new Mult();
        Console.WriteLine($"MultMany: ");
        object1.MultMany(numThreads);
        Console.WriteLine($"MultOne : ");
        object1.MultOne(numThreads);
    }
 
}