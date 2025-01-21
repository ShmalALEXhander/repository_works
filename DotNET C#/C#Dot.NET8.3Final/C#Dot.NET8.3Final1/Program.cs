using System;
using System.Net;
using System.Text;
using System.Xml.Linq;
using static Program;

class Program
{
    static void Main()
    {
        studDatabase DataBase = new studDatabase();
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
                case "6":
                    DataBase.removeExam();
                    break;
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
    class studDatabase
    {
        List<Student> students = new List<Student>();
        public void readStud()
        {
            string pathCurr = "C:\\Users\\Александр\\source\\repos\\C#Dot.NET8.3Final\\C#Dot.NET8.3Final1\\Base.txt";
            using (BinaryReader source = new BinaryReader(File.Open(pathCurr, FileMode.Open, FileAccess.Read)))
            {
                byte[] bytes = new byte[4096];
                int numBytesToRead = 4096;
                int numBytesRead = 0;
                // Делаю для сплошного списка символов без пробелов.
                while ((numBytesRead = source.Read(bytes, 0, bytes.Length)) > 0)
                {
                    char[] data = System.Text.Encoding.UTF8.GetChars(bytes, 0, numBytesRead);
                    int state = 0; // 0: family, 1: name, 2: otchestvo, 3: birth date, 4: address, 5: passport series
                    List<char> currentField = new List<char>();
                    Student student = new Student();
                    student.FromCharArray(data);
                    students.Add(student);
                }
            }
        }

        public void writeStud()
        {
            string pathNew = "C:\\Users\\Александр\\source\\repos\\C#Dot.NET8.3Final\\C#Dot.NET8.3Final1\\Base2.txt";
        }
        public void searchStud()
        {

        }
        public void addStud()
        {

        }
        public void removeStud()
        {

        }
        public void addExam()
        {

        }
        public void removeExam()
        {

        }
        public void PrintAverageScores()
        {

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

        private void FillField(char[] fieldData, int state)
        {
            switch (state)
            {
                case 0:
                    Array.Copy(fieldData, family, Math.Min(fieldData.Length, family.Length));
                    break;
                case 1:
                    Array.Copy(fieldData, name, Math.Min(fieldData.Length, name.Length));
                    break;
                case 2:
                    Array.Copy(fieldData, otchestvo, Math.Min(fieldData.Length, otchestvo.Length));
                    break;
                case 3:
                    BirthDate = DateTime.Parse(new string(fieldData));
                    break;
                case 4:
                    Array.Copy(fieldData, Address, Math.Min(fieldData.Length, Address.Length));
                    break;
                case 5:
                    Array.Copy(fieldData, PassportSeries, Math.Min(fieldData.Length, PassportSeries.Length));
                    break;
            }
        }
        public void FromCharArray(char[] data)
        {
            List<char> currentField = new List<char>();
            int state = 0; // 0: family, 1: name, 2: otchestvo, 3: birth date, 4: address, 5: passport series

            foreach (char c in data)
            {
                if (c == ',')
                {
                    // Переход к следующему полю
                    FillField(currentField.ToArray(), state);
                    currentField.Clear();
                    state++;
                }
                else if (c == '\n' || c == '\r')
                {
                    // Обработка конца строки
                    if (currentField.Count > 0)
                    {
                        FillField(currentField.ToArray(), state);
                        currentField.Clear();
                    }
                    break; // Выход из цикла
                }
                else
                {
                    currentField.Add(c);
                }
            }
        }
        public class Exam
        {
            public char[]? Subject { get; set; } // предмет
            public DateTime Data { get; set; }
            public double Grade { get; set; } // оценка      
        }
    }
}