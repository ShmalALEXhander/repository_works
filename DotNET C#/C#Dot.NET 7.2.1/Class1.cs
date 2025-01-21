using System;
using System.IO;
using System.Reflection;
using System.Xml.Linq;


namespace Lab {
    public interface IInterface1
    {
        public string GetName();
        public int GetAge();
        public double GetBalance();
    }
    public interface IInterface2
    {
        public void setName(string name_);
        public void SetAge(int age_);
        public void SetBalance(double balance_);
    }
    public class Class1 : IInterface1, IInterface2
    {
        static public string name; // поля стало общим для всех классов.
        private int age;
        private double balance;

        //public MyClass();      
        public Class1(string name_)
        {
            name = name_;
        }
        public Class1(string name_, int age_)
        {
            name = name_;
            age = age_;
        }
        public Class1(string name_, int age_, double balance_)
        {
            name = name_;
            age = age_;
            balance = balance_;
        }
        public string GetName() { return name; }
        public int GetAge() { return age; }
        public double GetBalance() { return balance; }
        public void setName(string name_)
        {
            name = name_;
        }
        public void SetAge(int age_)
        {
            if (age_ > 0)
            {
                age = age_;
            }
            else
            {
                throw new ArgumentException("Возраст не может быть отрицательным");
            }
        }
        public void SetBalance(double balance_)
        {
            balance = balance_;
        }
        public double addDeposit(double amount)
        {
            if (amount > 0)
            {
                balance += amount;
            }
            else
            {
                throw new ArgumentException("Сумма пополнения должна быть положительной");
            }
            return balance;
        }
        public double Takeoff(double amount)
        {
            if (amount > 0)
            {
                balance -= amount;
            }
            else
            {
                throw new ArgumentException("Нельзя снять отрицательую величину");
            }
            return balance;
        }
        public void DisplayInfo()
        {
            Console.WriteLine($"Name: {name}, Age: {age}, Balance: {balance}");
        }
    }
    public class MyTestClass1
    {
        public void GetFile(string className)
        {
            StreamWriter writer = new StreamWriter("output.txt");
            Type? type = Type.GetType(className); if (type == null) throw new ArgumentException($"Не удалось найти тип: {className}");
            Console.WriteLine($"Имя класса: {type.Name}");
            writer.WriteLine($"Имя класса: {type.Name}");
            Console.WriteLine($"Пространство имён: {type.Namespace}");
            writer.WriteLine($"Пространство имён: {type.Namespace}");
            Console.WriteLine("Методы:");
            writer.WriteLine("Методы:");
            MethodInfo[] methods = type.GetMethods();
            foreach(var method in methods) //Делегат указатель на функцию?
            {
                Console.WriteLine($"{method.ReturnType.Name} { method.Name} ");
                writer.WriteLine($"{method.ReturnType.Name} { method.Name} ");
            }
            Console.WriteLine("Свойства:");
            writer.WriteLine("Свойства:");
            PropertyInfo[] properties = type.GetProperties();
            foreach(var property in properties)
            {
                Console.WriteLine($" - {property.Name}");
                writer.WriteLine($" - {property.Name}");
            }
            writer.Flush();
        }
        public void GetFileCS(string className)
        {
            StreamWriter writer = new StreamWriter("csFIle.cs");
            //Поработать над содержимым вывода
            Type? type = Type.GetType(className); if (type == null) throw new ArgumentException($"Класс {className} не найден");           
            Console.WriteLine($"name Class: {type.Name}");
            writer.WriteLine($"name Class: {type.Name}");
            Console.WriteLine($"namespace: {type.Namespace}");
            writer.WriteLine($"namespace: {type.Namespace}");
            Console.WriteLine("Properties:");
            writer.WriteLine("Properties:");
            PropertyInfo[] properties = type.GetProperties();
            foreach (var property in properties)
            {
                Console.WriteLine($" - {property.Name}");
                writer.WriteLine($" - {property.Name}");
            }
            Console.WriteLine("Methods:");
            writer.WriteLine("Methods:");
            MethodInfo[] methods = type.GetMethods();
            foreach (var method in methods) {
                Console.WriteLine($"{method.ReturnType} {method.Name}");
                writer.WriteLine($"{method.ReturnType} {method.Name}");
            }
            Console.WriteLine("Constructors:");
            writer.WriteLine("Constructors:");
            ConstructorInfo[] constructors = type.GetConstructors();
            foreach (var constructor in constructors) {
                var CASES = constructor.IsPublic ? "public" : "unknow";
                Console.WriteLine($"{CASES} {constructor.Name}");
            }
            writer.Flush(); // Скинуть буфер. Основы Операционных систем работа . Таненбаум читай.
            // волшебный пинок.
        }
    }

    public class Program
    {
        static void Main()
        {
            //{// Тут сработал конструктор по-умолчанию.
            Class1 object1 = new Class1("Dmitr", 25);
            object1.DisplayInfo();
            Class1.name = "df"; //Вроде поломал парадигму ООП - инкапсуляцию.
            object1.DisplayInfo();
            MyTestClass1 Test = new MyTestClass1();
            // Test.GetFile("Lab.Class1");
            Test.GetFileCS("Lab.Class1");
        }
    }
    //}

}
