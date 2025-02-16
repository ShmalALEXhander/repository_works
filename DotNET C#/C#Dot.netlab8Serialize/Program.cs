using C_Dot.netlab8Serialize;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace C_Dot.netlab8Serialize
{
    class Program
    {
        public class rec
        {
            public fio? name;
            public DateOnly? birthday;
            public address? addr;
            public string? passport;           
            public rec(fio fio_, DateOnly birthday_, address addr_, string passport_)
            {
                name = fio_;
                birthday = birthday_;
                addr = addr_;
                passport = passport_;
                //Свой конструктор копирвоания.
            }
            public rec() { }
            public void print()
            {
                Console.WriteLine($"{name.surname} {name.name} {name.otch}");
                Console.WriteLine(birthday);
                Console.WriteLine($"{addr.index} {addr.city} {addr.street} {addr.building} {addr.room}");
                Console.WriteLine(passport + "\n");
            }
        }
        public class fio
        {
            public string? surname;
            public string? name;
            public string? otch;
            //подумать об инкапсуляции
            public fio() { }
            public fio(string surname_, string name_, string otch_)
            {
                
                surname = surname_;
                name = name_;
                otch = otch_;
            }
            public void print()
            {
                Console.WriteLine($"{surname} {name} {otch}");
            }         
        }
        public class address        
        {
            public int? index;
            public string? city;
            public string? street;
            public int? building;
            public int? room;
            public address() { }
            public address(int index_, string city_, string street_, int building_, int room_)
            {
                index = index_;
                city = city_;
                street = street_;
                building = building_;
                room = room_;
            }                  
        }
        public static void Main()
        {
            fio fio_1 = new fio("Petr", "Bashar", "Ibn");                                
            address addr_1 = new address(1, "Rostov", "Pushkina", 5, 8); 
            DateOnly date_ = new DateOnly(2004, 2, 29);
            rec record_1 = new rec(fio_1, date_, addr_1, "53463456");
            record_1.print();
            var options = new JsonSerializerOptions 
            { IncludeFields = true }; // глобальная настройка
            Console.WriteLine("Serializable:");
            string outdate = JsonSerializer.Serialize<rec>(record_1, options);
            Console.WriteLine(outdate);
            Console.WriteLine("\nDeserializable:");
            rec? record_2 = JsonSerializer.Deserialize<rec>(outdate, options);
            record_2.print();
            object record_3 = JsonSerializer.Deserialize<object>(outdate , options);

            //System.Web.WebPages.Html.Print(myObject); Как вывести поля класса Object
        }
    }
}


