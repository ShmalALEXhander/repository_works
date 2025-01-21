using System;
using System.Reflection;


namespace lab
{
    public interface IInterface1
    {
        public string GetName();
        public int GetAge();
        public double GetBalance();
    }
    public interface IInterface2
    {
        public void setName();
        public void SetAge();
        public void SetBalance();
    }
    class MyClass
    {
        private string name;
        private int age;
        private double balance;

        public MyClass(string name_, int age_, double balance_)
        {
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
    }
}