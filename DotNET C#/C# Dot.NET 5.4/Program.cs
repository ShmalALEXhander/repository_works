using System;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Runtime.Intrinsics;


class Program
{
    class primeNum
    {
        int count;
        //public primeNum(int count_)
        //{
        //    count = count_;
        //}
        private bool IsPrime(int num)
        {
            for (int i = 3; i * i <= num; i += 2)
                if (num % i == 0) return false;
            return true;
        }
        vector<int> primes(int n)
        {
            vector<int> v;
            if (n >= 1) v.push_back(2);
            for (int k = 3; v.size() < n; k += 2)
                if (is_prime(k)) v.push_back(k);
            return v;
        }
    }

    
    static void Main()
    {
        int N = 10;
        var primes = new primeNum(N);
        Console.WriteLine("Числовая последовательность: ");
        foreach (var prime in primes)
        {
            Console.Write($"{prime}");
        }
    }
}