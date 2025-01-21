using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net;
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
            string pathSource = "C:\\Users\\Александр\\source\\repos\\C#Dot.NET8.3Final\\C#Dot.NET8.3Finlishe\\Base.txt";           
            using (FileStream source = new FileStream(pathSource,
            FileMode.Open, FileAccess.Read))
            {
                byte[] bytes = new byte[4096];
                int numBytesToRead = 4096; // файл весит 2 гб, урезали до 31 бита
                int numBytesRead = 0;
                while ((numBytesRead = source.Read(bytes, 0, bytes.Length)) > 0)
                {
                    string data = System.Text.Encoding.UTF8.GetString(bytes, 0, numBytesRead);

                    string[] lines = data.Split(new[] { '\n' }, StringSplitOptions.RemoveEmptyEntries);
                    foreach (var line in lines)
                    {
                        var parts = line.Split(',');
                        if(parts.Length > 0)
                        {
                            var student = new Student
                            {
                                family = parts[0],
                                name = parts[1],
                                otchestvo = parts[2],
                                Address = parts[3],
                                PassportSeries = parts[4]
                            };

                        }
                    }

                    int n = source.Read(bytes, numBytesRead, numBytesToRead);
                    if (n == 0)
                        break;

                    numBytesRead += n; // какой бы ни был размер файла, мы читаем его блоками до 2 гб.
                    numBytesToRead -= n;
                }
                numBytesToRead = bytes.Length;
            }           
        }
         // +++
        public void writeStud()
        {
            using (FileStream writer = new FileStream("C:\\Users\\Александр\\source\\repos\\C#Dot.NET8.3Final\\C#Dot.NET8.3Finlishe\\Base3.txt"))
            {
                foreach (var student in students)
                {
                    string? str = student.ToString();
                    writer.WriteLine(str);
                    //if (student.Exams != null) // Пиши в разные таблицы.
                    //{
                    //    str = student.Exams.ToString(1);
                    //    writer.WriteLine(str);
                    //}
                }
            }
        } //
        public void addStud()
        {
            Console.WriteLine("Give family"); char? family_ = Console.ReadLine();
            Console.WriteLine("Give name"); char? name_ = Console.ReadLine();
            Console.WriteLine("Give otchestvo"); char? otchestvo_ = Console.ReadLine();
            Console.WriteLine("Введите дату рождения (дд.мм.гггг):"); DateTime birthDate_ = DateTime.Parse(Console.ReadLine());
            Console.WriteLine("Введите адрес:"); char? address_ = Console.ReadLine();
            Console.WriteLine("Введите серию паспорта"); char? passportSeries_ = Console.ReadLine();

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
                Console.WriteLine("Name subject :"); string subject[ = Console.ReadLine();
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
            else { Console.WriteLine("Студент не найден."); }
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
        public Student() { }
        public Student(char[] family_, char[] name_, char[] otchestvo_, DateTime BirthDate_, char[] Address_, char[] PassportSeries_)
        {
            family = family_;
            name = name_;
            otchestvo = otchestvo_;
            BirthDate = BirthDate_;
            Address = Address_;
            PassportSeries = PassportSeries_;
        }
        public List<Exam> Exams { get; set; } = new List<Exam>();
        public char[] family = new char[16];
        public char[] name = new char[16];
        public char[] otchestvo = new char[16];
        public DateTime BirthDate;
        public char[] Address = new char[16];
        public char[] PassportSeries = new char[16];
        public double AverageScore => Exams.Count > 0 ? Exams.Average(e => e.Grade) : 0.0;
        //public override string ToString()
        //{
        //    return $"{family} {name} {otchestvo}, {BirthDate.ToShortDateString()}, Address: {Address}, Паспорт: {PassportSeries}";
        //}
        public char[] ToCharArray()
        {
            string result = $"{family} {name} {otchestvo}, {BirthDate.ToShortDateString()}, Address: {Address}, Паспорт: {PassportSeries}";
            return result.ToCharArray();
        }
    }
    public class Exam
    {
        public char[]? Subject { get; set; } // предмет
        public DateTime Data { get; set; }
        public double Grade { get; set; } // оценка      
    }
}
