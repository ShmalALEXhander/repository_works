using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Text.Json;

namespace C_Dot.netlab8Serialize
{
    [DataContract]
    class Program
    {
        [DataContract]
        public class rec
        {
            [DataMember]
            public fio? name;
            [DataMember]
            public DateOnly? birthday;
            [DataMember]
            public address? addr;
            [DataMember]
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
        [DataContract]
        public class fio
        {
            [DataMember]
            public string? surname;
            [DataMember]
            public string? name;
            [DataMember]
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
        [DataContract]
        public class address
        {
            [DataMember]
            public int? index;
            [DataMember]
            public string? city;
            [DataMember]
            public string? street;
            [DataMember]
            public int? building;
            [DataMember]
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
        public static void Main() //На базовом уровне сериализация обоих классов не различалась по применению
        { //Объекты классов
            fio fio_1 = new fio("Petr", "Bashar", "Ibn");
            address addr_1 = new address(1, "Rostov", "Pushkina", 5, 8);
            DateOnly date_ = new DateOnly(2004, 2, 29);
            rec record_1 = new rec(fio_1, date_, addr_1, "53463456");
            rec record_1v2 = new rec(fio_1, date_, addr_1, "444444444");
            //rec[] recs1 = new rec[] { record_1, record_1v2 };
            //Тест вложенности JSON
            record_1.print();
            var options = new JsonSerializerOptions
            { IncludeFields = true }; // глобальная настройка
            Console.WriteLine("Serializable:");
            string outdate = JsonSerializer.Serialize<rec>(record_1, options);
            Console.WriteLine(outdate);
            Console.WriteLine("\nDeserializable:");
            rec? record_2 = JsonSerializer.Deserialize<rec>(outdate, options);
            record_2.print();
            object record_3 = JsonSerializer.Deserialize<object>(outdate, options);
            ////////////////////Сериализация с файлом
            using (FileStream fs_v2 = new FileStream("Test.json", FileMode.OpenOrCreate))          
                JsonSerializer.Serialize<rec>(fs_v2, record_1v2, options);           
            using (FileStream fs = new FileStream("Test.json", FileMode.OpenOrCreate))
            {
                var record_1v3 = JsonSerializer.Deserialize<rec>(fs, options);
                Console.WriteLine("**********************");
                record_1v3.print();
            }
            //Сериализаця с помощью DataContractJsonSerializer
            rec record_1v4 = new rec(fio_1, date_, addr_1, "11111111111111111");
            rec record_1v5 = new rec(fio_1, date_, addr_1, "22222222222222222");
            rec[] recs = new rec[] {record_1v4,record_1v5 };
            var jsonF = new DataContractJsonSerializer(typeof(rec[]));
            using (FileStream fs = new FileStream("my.json", FileMode.OpenOrCreate))
                jsonF.WriteObject(fs, recs);
        }
    }
}//System.Web.WebPages.Html.Print(myObject); Как вывести поля класса Object


