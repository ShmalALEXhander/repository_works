using System;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        string pathCurr = "C:\\Users\\Александр\\source\\repos\\Dot.NetC#BinaryFile\\Dot.NetC#BinaryFile\\ReadFile.txt";
        string pathNew = "C:\\Users\\Александр\\source\\repos\\Dot.NetC#BinaryFile\\Dot.NetC#BinaryFile\\WriteFile.bin";

        Person[] people =
        {
            new Person("Tom", 37),
            new Person("Bob", 45)
        };
        using (BinaryWriter binary = new BinaryWriter(File.Open(pathNew, FileMode.OpenOrCreate)))
        {
            foreach (Person person in people)
            {
                binary.Write(person.Name);
                binary.Write(person.Age);
            }
        }
    }
}
class Person
{
    public string Name { get; set; }
    public int Age { get; set; }
    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }
}