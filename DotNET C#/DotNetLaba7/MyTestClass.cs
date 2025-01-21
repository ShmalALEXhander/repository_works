using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using System.IO;
using System.Drawing.Printing;
using System.Runtime.CompilerServices;

namespace DotNetLaba7
{
    internal class MyTestClass
    {
        static public void getStrMethod(Type t)
        {
            Console.WriteLine("Методы со строковыми параметрами: ");
            foreach (MethodInfo m in t.GetMethods())
            {
                bool flag = false;
                foreach (ParameterInfo p in m.GetParameters())
                {
                    if (p.ParameterType == typeof(string)) flag = true;

                }
                if (flag)
                {
                    Console.WriteLine(" {0}", m.Name);
                }
            }
        }

        static public void RunMethod(string className, string method, string arg1, string arg2)
        {
            Type nClass = Type.GetType(className);
            MethodInfo nMethod = nClass.GetMethod(method);
            string[] args = { arg1, arg2 };
            nMethod.Invoke(null, args);
        }
        
        public void PrintClassContent(string className){
            Type type = Type.GetType(className);
            if (type != null){
                using (StreamWriter writer = new StreamWriter($"{className}.txt")){
                    foreach (FieldInfo field in type.GetFields()){
                        writer.WriteLine($"{field.FieldType} {field.Name};");
                    }
                    foreach (MethodInfo method in type.GetMethods()){
                        writer.WriteLine($"{method.ReturnType} {method.Name}();");
                    }
                }
            }
            else {
                Console.WriteLine("Класс не найден.");
            }
        }
    }
    public class AnotherTestClass
    {
        public static void printSum(string str1, string str2)
        {
            Console.WriteLine("Сгенерированная строка: "+str2 +" "+ str1);
        }
    }

}
