using System;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        string s = "2 6 5 7 4 9 3 1 8 3 0";
        var numbers = s.Split(' ');
        mySet set = new mySet();
        foreach (string number in numbers)
        {
            set.Add(int.Parse(number));
        }
        set.Sort(false);
        IEnumerable Range (int init, int upTo){
            Console.WriteLine(" ");
            for (int i = init; i < upTo; i++)
                yield return i;
        }

        Console.WriteLine(" ");
        foreach (var number in set)
        {
            if (number % 2 == 0)
                Console.WriteLine(number);
        }
    }
    public class Mass {}
    class mySet
    {
        private const int step = 10;
        private int size = step;
        private int cnt = 0;
        public int Count;
        private int[] arr;


        public mySet()
        {
            arr = new int[size];
            Count = cnt;
        }

        public void Add(int num)
        {
            for (int i = 0; i < cnt; i++)
            {
                if (arr[i] == num) return;
            }
            if (cnt == size)
            {
                size += step;
                int[] newarr = new int[size];
                for (int i = 0; i < cnt; i++)
                {
                    newarr[i] = arr[i];
                }
                arr = newarr;
            }
            arr[cnt] = num;
            cnt++;
            Count = cnt;
        }

        public int get(int i) { return arr[i]; }

        public void Sort(bool reverse = true)
        {
            bool flag = true;

            if (reverse)
            {
                while (flag)
                {
                    flag = false;
                    for (int i = 0; i < cnt - 1; ++i)                                           
                    {
                        if (arr[i + 1] < arr[i])
                        {
                            int tmp = arr[i];
                            arr[i] = arr[i + 1];
                            arr[i + 1] = tmp;
                            flag = true;
                        }
                    }
                }
            }
            else
            {
                while (flag)
                {
                    flag = false;
                    for (int i = 0; i < cnt - 1; ++i)
                    {
                        if (arr[i + 1] > arr[i])
                        {
                            int tmp = arr[i];
                            arr[i] = arr[i + 1];
                            arr[i + 1] = tmp;
                            flag = true;
                        }
                    }
                }
            }
        }
        public IEnumerator<int> GetEnumerator() => new mySetEnumerator(arr);

    }

    public class mySetEnumerator : IEnumerator<int>
    {
        int[] arr;
        int pos = -1;

        public mySetEnumerator(int[] arr) => this.arr = arr;
        public int Current
        {
            get
            {
                if (pos == -1 || pos >= arr.Length)
                    throw new ArgumentException();
                return arr[pos];
            }
        }
        object IEnumerator.Current => Current;
        public bool MoveNext()
        {
            if (pos < arr.Length - 1)
            {
                pos++;
                return true;
            }
            else return false;
        }
        public void Reset() => pos = -1;
        public void Dispose() { }
    }

}