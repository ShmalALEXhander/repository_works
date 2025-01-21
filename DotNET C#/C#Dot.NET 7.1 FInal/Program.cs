//Для первой части задачи можно использовать такое условие
//Создай класс с именем(скорее идентификатором), возрастом и балансом пользователя
using System.Reflection;

namespace Lab
{
    public class MyClass{
        private string name;
        private int age;
        private double balance;
        public MyClass(string name_, int age_, double balance_){
            name = name_;
            age = age_;
            balance = balance_;
        }
        public string GetName() { return name; }
        public int GetAge() { return age; }
        public double GetBalance() { return balance; }
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
        public static void DisplayInfo1(string name_, string age_, string balance_)
        {
            Console.WriteLine($"Name: {name_}, Age: {age_}, Balance: {balance_}");
        }
        public static void DisplayInfo2(string name)
        {
            Console.WriteLine($"Name: {name}");
        }
    }
    class MyTestClass
    {    
        public static void getMethodsStrings(string className){
            Type? type = Type.GetType(className);
            if (type == null) throw new ArgumentException($"Класс {className} не найден");
            foreach (MethodInfo method in type.GetMethods())
            {
                var arrParams = method.GetParameters();
                foreach (var el in arrParams)
                {
                    if (el.ParameterType.FullName == "System.String")
                    { // есть ли System string .... записываешь в хранилище для обработки.
                        Console.Write(type.Name + " ");
                        Console.Write(method.Name + " ");
                        Console.WriteLine(el);
                    }
                }
            }      
            //var r1 = type.GetMethods(BindingFlags.Instance | BindingFlags.Public);
       
            //var r2 = r1.Where(m => m.GetParameters().Any(p => p.ParameterType == typeof(string)));
            //var r3 = r2.Select(m => m.Name);
            //var r4 = r3.ToArray();
            //var res= type.GetMethods(BindingFlags.Instance | BindingFlags.Public).Where(m => m.GetParameters().Any(p => p.ParameterType == typeof(string))).Select(m => m.Name).ToArray();
            //return res;
           
        }
        public static void CallMethodFile(string className, string methodName, string filename){              
            string[] parameters = File.ReadAllText(filename).Trim().Split(' ');
            // Метод GetType - изначально статические , и т.к. нет никакого объекта класса п 
            Type? type = Type.GetType(className); if (type == null) throw new ArgumentException($"Класс {className} не найден"); // Обращаюсь к к классу у которого есть статический метод геттайп.
            MethodInfo? method = type.GetMethod(methodName); if (method == null) throw new ArgumentException($"Метод '{methodName}' не найден в классе '{className}'");

            object[] convParams = parameters.Select(p => Convert.ChangeType(p, method.GetParameters()[0].ParameterType)).ToArray();
                                                 //    //Это вызывается в p. Возвращается функия а не переменная. Делегат                                                     //
            method.Invoke(null, convParams);// передача
        }
    }    
    public class Program
    {
        static void Main()
        {
            MyClass myObject1 = new MyClass("Dmitriy", 30, 1000);
            myObject1.DisplayInfo(); 
            myObject1.SetAge(35);
            myObject1.DisplayInfo();
            myObject1.Takeoff(3000);
            myObject1.Takeoff(100);
            myObject1.DisplayInfo();
            myObject1.addDeposit(5000);
            myObject1.DisplayInfo();
            MyClass myObject2 = new MyClass("Sergey", 49, 3000);
            MyClass myObject3 = new MyClass("Yaroslav", 27, 5000);
            MyClass myObject4 = new MyClass("Vilgeym", 33, 2300);
            MyClass myObject5 = new MyClass("Gans", 45, 7000);
            // var methodsWithStringParams = MyTestClass.getMethodsStrings("Lab.MyTestClass");
            // Console.WriteLine("Методы с строковыми параметрами: " + string.Join(", ", methodsWithStringParams));           
            MyTestClass.CallMethodFile("Lab.MyClass", "DisplayInfo1", "File.txt");
            Console.WriteLine("//////////////////////");
            MyTestClass.getMethodsStrings("Lab.MyClass");
        }
    }
}