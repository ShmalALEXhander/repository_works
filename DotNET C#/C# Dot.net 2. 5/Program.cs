using System;
using System.Reflection;
using System.Runtime.Intrinsics.Arm;
using System.Security.Cryptography.X509Certificates;
namespace ComputerComponent;
public class ComputerEquipment
{
    public string Model { get; set; }
    public string Brand { get; set; }

    public virtual void DisplayInfo()
    {
        Console.WriteLine($"Model {Model}, Brand {Brand}");
    }
}
 public class Computer : ComputerEquipment
{
    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine("Процессор Ryzen 7 4800H");
    }
}
public class Printer : ComputerEquipment
{
    int Size { get; set; }
    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Size {Size}"); 
    }
}
class Monitor : ComputerEquipment
{
    int RefreshRate { get; set; }
    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"RefreshRate {RefreshRate}");
    }
}
class AudioSpeaker : ComputerEquipment
{
    int Volume { get; set; }
    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Volume : {Volume}");
    }
}
class StorageDevice : ComputerEquipment
{
    public int memCapacity { get; set; }// Нехорошая практика ограничиваться геттерами и сеттерами не испльзую контструкторы
    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"MemoryCapacity : {memCapacity}");
    }
}class HardDisk : StorageDevice
{
    public int RPM { get; set; } //Множественное наследование не поддерживаетс в С# . Наследовать можно только от 1 го класа. Пример: Летающие и млекопитающие. Летучая мышь.
    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Rpm {RPM}");
    }
}
class RemovableDisk : StorageDevice
{
    bool isFlash { get; set; }
    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"is Flash? : {isFlash}");
    }
}
class Program
{
    static void Main(string[] args)
    {
        // В С# родительский контсруктор можно специально вызвать принудительно
        Printer a = new Printer { Model = "123", Brand = "Opel" };
        a.DisplayInfo();
        HardDisk b = new HardDisk { 
        Brand = "Seagate", Model = "Barracuda", memCapacity = 1000, RPM = 7200
        }; //  принудительно обращаемся к конструктору по-умолчанию
        Printer f = new Printer("123", "Apple");
        
        b.DisplayInfo();
    }
}









