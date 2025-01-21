using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using static System.Runtime.InteropServices.JavaScript.JSType;

class Program
{
    static void Main()
    {
        StudentDatabase DataBase = new StudentDatabase();
        while (true)
        {
            Console.WriteLine("\nВыберите действие:");
            Console.WriteLine("1. Cчитать данные из файла");
            Console.WriteLine("2. Поиск студента");
            Console.WriteLine("3. Добавить студента");
            Console.WriteLine("4. Удалить студента");
            Console.WriteLine("5. Добавить экзамен");
            Console.WriteLine("6. Удалить экзамен");
            Console.WriteLine("7. Отчёт о среднем балле"); // Тут сериализация.
            Console.WriteLine("8. Записать данные в файл");
            Console.WriteLine("9. Выход");
            string choice = Console.ReadLine();
            switch (choice) 
            {
                case "1":
                    DataBase.readStud();
                    break;
                case "2":
                    DataBase.searchStud();                   
                    break;
                case "3":
                    DataBase.addStud();
                    break;
                case "4":
                    DataBase.removeStud();
                    break;
                case "5":
                    DataBase.addExam();
                    break;
                //case "6":
                //    DataBase.removeExam();
                //    break;
                case "7":
                    DataBase.PrintAverageScores(); //успеваемость
                    break;
                case "8":
                    DataBase.writeStud();
                    break;
                case "9":
                    return;
                default:
                    Console.WriteLine("Неверный выбор, попробуйте снова");
                    break;
            }
        }
    }

    class StudentDatabase
    {
        public List<Student> students = new List<Student>();
        public void readStud()
        {
            using (StreamReader reader = new StreamReader("C:\\Users\\Александр\\source\\repos\\C#Dot.NET8.3Final\\Base.txt"))
            {
                string? line;
                while ((line = reader.ReadLine()) != null)
                {
                    var a = line.Split(',');
                    
                    students.Add(new Student(a[0], a[1], a[2], DateTime.Parse(a[3]), a[4], a[5]));
                }

            }
               
        } // +++
        public void writeStud()
        {
            using (StreamWriter writer = new StreamWriter("C:\\Users\\Александр\\source\\repos\\C#Dot.NET8.3Final\\Base2.txt"))
            {
                foreach (var student in students)
                {
                    string? str = student.ToString();
                    writer.WriteLine(str);
                    if (student.Exams != null)
                    {
                        str = student.Exams.ToString(1);
                        writer.WriteLine(str);
                    }
                }
            }
        } //
        public void addStud()
        {
            Console.WriteLine("Give family"); string? family_ = Console.ReadLine();
            Console.WriteLine("Give name"); string? name_ = Console.ReadLine();
            Console.WriteLine("Give otchestvo"); string? otchestvo_ = Console.ReadLine();
            Console.WriteLine("Введите дату рождения (дд.мм.гггг):"); DateTime birthDate_ = DateTime.Parse(Console.ReadLine());
            Console.WriteLine("Введите адрес:"); string? address_ = Console.ReadLine();
            Console.WriteLine("Введите серию паспорта"); string? passportSeries_ = Console.ReadLine();

            Student newStudent = new Student(family_, name_, otchestvo_, birthDate_, address_, passportSeries_);
            students.Add(newStudent);
        }
        public void removeStud()
        {
            string family = Console.ReadLine();
            Student RemoveStud = students.FirstOrDefault(s => s.family.Equals(family, StringComparison.OrdinalIgnoreCase));
            if (RemoveStud != null)
            {
                students.Remove(RemoveStud);
                Console.WriteLine("Студент успешно удалён.");
            }
            else
            {
                Console.WriteLine("Студент не найден.");
            }
        }
        public void searchStud()
        {
            string family = Console.ReadLine();
            Student searchStud = students.FirstOrDefault(s => s.family.Equals(family, StringComparison.Ordinal));
            if (searchStud != null)
            {
                Console.WriteLine(searchStud);
                // Console.WriteLine("Экзамены:");
                foreach (var exam in searchStud.Exams)
                {
                    Console.WriteLine($"- {exam.Subject}, Дата: {exam.Data.ToShortDateString()}, Оценка: {exam.Grade}");
                }
            }
            else
            {
                Console.WriteLine("Студент не найден.");
            }
        }
        public void addExam()
        {
            string family = Console.ReadLine();
            Student student = students.FirstOrDefault(s => s.family.Equals(family, StringComparison.OrdinalIgnoreCase));
            if (student != null)
            {
                Console.WriteLine("Name subject :"); string subject = Console.ReadLine();
                Console.WriteLine("Data exam subject (дд.мм.гггг):"); DateTime examDate = DateTime.Parse(Console.ReadLine());
                Console.WriteLine("Grade :"); double grade = double.Parse(Console.ReadLine());
                Exam newExam = new Exam
                {
                    Subject = subject,
                    Data = examDate,
                    Grade = grade
                };
                student.Exams.Add(newExam);
            }
            else {Console.WriteLine("Студент не найден."); }
        }
        //public void removeExam()
        //{
        //    string family = Console.ReadLine();
        //    Student student = students.FirstOrDefault(s => s.family.Equals(family, StringComparison.OrdinalIgnoreCase));
        //    student.Exams.Remove()

        //}
        public void PrintAverageScores()
        {
            foreach (var student in students)
            {
                Console.WriteLine($"{student.family} {student.name}: Средний балл = {student.AverageScore:F2}");
            }
        }
    }
    public class Student
    {
        public Student(string family_, string name_, string otchestvo_, DateTime BirthDate_, string Address_, string PassportSeries_)
        {
            family = family_.TrimStart();
            name = name_.TrimStart();
            otchestvo = otchestvo_.TrimStart();
            BirthDate = BirthDate_;
            Address = Address_.TrimStart();
            PassportSeries = PassportSeries_.TrimStart();
        }
        public List<Exam> Exams { get; set; } = new List<Exam>();
        public string family;
        public string name;
        public string otchestvo;
        public DateTime BirthDate;
        public string Address;
        public string PassportSeries;
        public double AverageScore => Exams.Count > 0 ? Exams.Average(e => e.Grade) : 0.0;
        public override string ToString()
        {
            return $"{family} {name} {otchestvo}, {BirthDate.ToShortDateString()}, Addres: {Address}, Паспорт: {PassportSeries}";

        }
        public override string ToString(int num)
        {
            return $"{Subject}";

        }
    }
    public class Exam
    {
        public string Subject { get; set; } // предмет
        public DateTime Data { get; set; }
        public double Grade { get; set; } // оценка      
    }
}
