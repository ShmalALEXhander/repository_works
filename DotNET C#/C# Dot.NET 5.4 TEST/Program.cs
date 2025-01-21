using System;
using System.Collections;
using System.Collections.Generic;

public class PrimeNumbers : IEnumerable<int>
{
    private readonly int _count;
    public PrimeNumbers(int count)
    {
        if (count < 1)
        {
            throw new ArgumentOutOfRangeException(nameof(count), "Count must be at least 1.");
        }
        _count = count;
    }
    public IEnumerator<int> GetEnumerator()
    {
        return new PrimeEnumerator(_count);
    }
    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
    private class PrimeEnumerator : IEnumerator<int>
    {
        private readonly int count;
        private int currIndex;
        private int currPrime;

        public PrimeEnumerator(int count_)
        {
            count = count_;
            currIndex = 0;
            currPrime = 1; // Начальное значение, которое не является простым
        }
        public int Current => currPrime;
        object IEnumerator.Current => Current;
        public bool MoveNext()
        {
            while (currIndex < count)
            {
                currPrime++;
                if (IsPrime(currPrime))
                {
                    currIndex++;
                    return true;
                }
            }
            return false;
        }
        public void Reset()
        {
            currIndex = 0;
            currPrime = 1;
        }
        public void Dispose()
        {
            // Здесь можно освободить ресурсы, если нужно
        }
        private bool IsPrime(int number)
        {
            if (number < 2) return false;
            for (int i = 2; i <= Math.Sqrt(number); i++)
            {
                if (number % i == 0) return false;
            }
            return true;
        }
    }
}
class Program
{
    static void Main(string[] args)
    {
        int N = 10; // Задайте количество простых чисел для генерации
        var primes = new PrimeNumbers(N);

        Console.WriteLine("Числовая последовательность:");
        foreach (var prime in primes)
        {
            Console.Write($"{prime} ");
        }
    }
}