using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DotNetLaba7
{

    public interface Interface1
    {
        int GetByID(int id);
        int GetByID(string Name); //как соединить
    }
    public interface Interface2
    {       
        int GetByID(int id, int DebugParam);
    }
    public class MyClass : Interface2
    {
        [DebugPrint("{0:0.00}")]
        public double Value { get; set; } = 3.14159;

        [DebugPrint("{0}")]
        public string Name1 { get; set; } = "Dikaprio";
        public static int ID { get; set; }
        public string Name { get; set; }
        public int DebugParam { get; set; }  // Добавленное свойство для отладочных параметров

        public MyClass()
        {
            // Конструктор без параметров
        }

        public MyClass(int id, string name, int debugParam)
        {
            ID = id;
            Name = name;
            DebugParam = debugParam;
        }

        public void PerformAction()
        {
            Console.WriteLine($"Выполняется действие для объекта с ID {ID} и именем {Name}");
        }      
        public int GetByID(int id)
        {
            return id;
        }
        public string GetByID(string Name)
        {
            return Name;
        }
        public int GetByID(int id, int DebugParam)
        {
            return DebugParam;
        }


    }
    [AttributeUsage(AttributeTargets.Property | AttributeTargets.Field)]
    public class DebugPrintAttribute : Attribute
    {
        public string Format { get; }

        public DebugPrintAttribute(string format = "{0}")
        {
            Format = format;
        }
    }

    public class DebugPrinter
    {
        public static void PrintObject(object obj)
        {
            var type = obj.GetType();
            var properties = type.GetProperties();
            var fields = type.GetFields();

            foreach (var property in properties)
            {
                var debugAttr = (DebugPrintAttribute)Attribute.GetCustomAttribute(property, typeof(DebugPrintAttribute));
                if (debugAttr != null)
                {
                    var value = property.GetValue(obj);
                    Console.WriteLine($"{property.Name}={string.Format(debugAttr.Format, value)}");
                }
            }

            foreach (var field in fields)
            {
                var debugAttr = (DebugPrintAttribute)Attribute.GetCustomAttribute(field, typeof(DebugPrintAttribute));
                if (debugAttr != null)
                {
                    var value = field.GetValue(obj);
                    Console.WriteLine($"{field.Name}={string.Format(debugAttr.Format, value)}");
                }
            }
        }
    }
    public class DopClass
    {
        public int a = 0;
        public DopClass(int a_)
        {
            a = a_;
        }
        public int AddElem(int b_)
        {
            a += b_;
            return a;
        }
        public int Multip(int b_)
        {
            a *= b_;
            return a;
        }
    }
}
