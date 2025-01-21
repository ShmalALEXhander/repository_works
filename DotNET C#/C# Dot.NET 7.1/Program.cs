using System;
using System.Reflection;

class MyClass
{
    int x;
    int y;

    public MyClass(int i, int j)
    {
        this.x = i;
        this.y = j;
    }

    public int sum()
    {
        Console.WriteLine(x + y);
        return x + y;
    }

    public void set()
    {
        x = 0;
        y = 0;
        Console.WriteLine($"x и y установлены в: {x}, {y}");
    }

    public void set(double a, double b)
    {
        x = (int)a;
        y = (int)b;
        Console.WriteLine($"x установлен в: {x}, y установлен в: {y}");
    }
}

class ReflectDemo
{
    public static void Main()
    {
        MyClass myObject = new MyClass(5, 10);

        // Получаем объект типа, представляющий MyClass
        Type t = typeof(MyClass);
        Console.WriteLine("Поддерживаемые методы: ");

        foreach (MethodInfo m in t.GetMethods())
        {
            // Отображаем тип результата и имя метода
            Console.WriteLine(" {0} {1}(…)", m.ReturnType.Name, m.Name);
        }

        Console.WriteLine();

        // Вызов метода sum
        MethodInfo sumMethod = t.GetMethod("sum");
        if (sumMethod != null)
        {
            object result = sumMethod.Invoke(myObject, null);
            Console.WriteLine("Результат вызова Sum: " + result);
        }
        else
        {
            Console.WriteLine("Метод sum не найден.");
        }

        // Вызов метода set с параметрами
        MethodInfo setMethod = t.GetMethod("set", new Type[] { typeof(double), typeof(double) });
        if (setMethod != null)
        {
            object[] parameters = { 20, 30 };
            setMethod.Invoke(myObject, parameters);
            Console.WriteLine("Метод set вызван.");
        }
        else
        {
            Console.WriteLine("Метод set с параметрами не найден.");
        }

        // Вызов метода sum снова после установки новых значений
        if (sumMethod != null)
        {
            object resultAfterSet = sumMethod.Invoke(myObject, null);
            Console.WriteLine("Результат вызова Sum после set: " + resultAfterSet);
        }
        else
        {
            Console.WriteLine("Метод sum не найден для второго вызова.");
        }
    } // Main
}
