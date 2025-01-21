using System;

namespace DelegateExample 
{
    public delegate int MathOperation(int a, int b); // ЭТО ПРОСТОЙ ДЕЛЕГАТ , 

    class Program
    {
        static int Add(int a, int b)
        {
            return a + b;
        }
        static int Remove(int a, int b)
        {
            return a - b;
        }
        static void PerformOperation(int a, int b, MathOperation operation) // Упоминание какая должна быть функция (параметры)
        {
            int result = operation(a,b);
            Console.WriteLine($"Результат операции: {result}");
        }
        static void Main()
        {
            int x = 8;
            int y = 2;
            PerformOperation(x, y, Add);
            Console.WriteLine(" ");
            PerformOperation(x, y, Remove);
        }
    }
}