using System;
using System.Numerics;
using System.Threading;
using System.Diagnostics;

class ABVG
    {
    public static List<int> mass1 = new List<int>();
    public static List<int> mass2 = new List<int>();

    public static void qsort()
    {
        Console.WriteLine("Qsort start");
        quick_sort(mass1, 0, mass1.Count()-1);        
        Console.WriteLine("Quick stop");
    }
    public static void quick_sort(List<int> list, int first, int last) // С листом что-то
        {
            if (first < last)
            {
                int left = first;
                int right = last;
                int middle = list[(left + right) / 2];
                do
                {
                    while (list[left] < middle)
                        left++;
                    while (list[right] > middle)
                        right--;
                    if (left <= right)
                    {
                        int tmp = list[left];
                        list[left] = list[right];
                        list[right] = tmp;
                        left++;
                        right--;
                    }
                } while (left < right);
                quick_sort(list, first, right);
                quick_sort(list, left, last);
            }
        }

    public static void rsort()
    {
        Console.WriteLine("Radix start");
        radix_sort(mass2, 8);
        Console.WriteLine("Radix stop");
    }
    public static void radix_sort(List<int> mass, int cols)
    {
        List<List<int>> buskets = new List<List<int>>(10);
        for (int i = 0; i < 10; i++)
        {
            List<int> row = new List<int>(cols);
            for (int j = 0; j < cols; j++)
            {
                row.Add(0);
            }
            buskets.Add(row);
        }
        //Конструктор по-умолчанию;
        // Скобочки является вызовом конструктора или конструктора по-умолчанию .
        int power_of_ten = 1;
        int max_num = 10000;
        int d = 0;
        while (max_num > 0)
        {
            max_num /= 10;
            d++;
        }
        for (int pow = 0; pow < d; ++pow)
        {
            foreach (var elem in mass)
            {
                buskets[elem / power_of_ten % 10].Add(elem);
            }
            mass.Clear();
            for (int i = 0; i < buskets.Count(); ++i)
            {
                for (int j = 0; j < buskets[i].Count(); ++j)
                {
                    mass.Add(buskets[i][j]);
                }
                buskets[i].Clear();
            }
            power_of_ten *= 10;
        }
    }
    // Код всегда в какой-то функции , а вот если for воспльзоватеься в мейне без функции то он автоматом предлагает воспользоваться ТИПОМ для ОПИСАНИЯ, по мнению анализатора кода - microsoft документацию.

    public static void Main()
    {
        const int size = 1000000;
        Random rnd = new Random();
        mass1 = new List<int>();
        Stopwatch sw = new Stopwatch();
        for (int i = 0; i < size; i++)
            mass1.Add(rnd.Next() % 1000);
        mass2 = new List<int>();
        for (int i = 0; i < size; i++)
            mass2.Add(rnd.Next() % 1000);
        Thread potok1 = new Thread(rsort);
        sw.Stop();
        potok1.Start();
        sw.Start();

        Console.WriteLine($"radix_sort {sw} seconds");

        Thread potok2 = new Thread(qsort);
        sw.Start();
        potok2.Start();
        sw.Stop();

        Console.WriteLine($"quick_sort {sw} seconds");
        
    }

}