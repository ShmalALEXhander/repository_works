using System.Runtime.InteropServices;

class Program{
    // это есть событие
    public delegate void DConnectHandler(string deviceName);
    interface IUsbBus{
        const int speed = 5;
        const int byteMove = 0; //не нужно public, оно по-умолчанию есть.
        bool Connect();
    }
    interface ISata{
        const int speed = 150;
        const int byteMove = 0;
        bool Connect();
    }
    interface INetwork{
        const int speed = 500; // лучше их писать.
        const int byteMove = 0;
        bool Connect();
    }
    interface IInnerBus{
        const int speed = 10000;
        const int byteMove = 55;
        bool Connect();
    }
    class MotherBoard : IInnerBus, IUsbBus, ISata{
        public event DConnectHandler DConnected; // событие подключения устройства
        int USBSpeed = 3;
        int SATASpeed = 145;
        int BUSSpeed = 9500;
        bool IInnerBus.Connect(){
            if (IInnerBus.speed == BUSSpeed) {
                Console.WriteLine("Можно подключить");
                DConnected?.Invoke("Внутренняя шина");return true;
            }
            else{
                Console.WriteLine("Нельзя подключить"); return false;
            }
        }
        bool IUsbBus.Connect(){ // Что тут происходит ??
            if (IUsbBus.speed == USBSpeed){
                Console.WriteLine("Можно подключить");
                DConnected?.Invoke("USB устройство"); return true;
            }
            else{
                Console.WriteLine("Нельзя подключить"); return false;
            }
        }
        bool ISata.Connect(){ // вообще можно Program.ISata.Connect() просто обращаюсь к полю класса?
            if (ISata.speed == SATASpeed){
                Console.WriteLine("Можно подключить");
                DConnected?.Invoke("SATA устройство"); return true;
            }
            else{
                Console.WriteLine("Нельзя подключить"); return false;
            }
        }
    }
    class RamMemory : IInnerBus{
        public event DConnectHandler DConnected;
        int InnerSpeed = 10;
        bool IInnerBus.Connect(){
            if (IInnerBus.speed == InnerSpeed){
                Console.WriteLine("Можно подключить");
                DConnected?.Invoke("Внутренняя шина"); return true;
            }
            else{
                Console.WriteLine("Нельзя подключить"); return false;
            }
        }
    }
    class HardDisk : ISata{
        public event DConnectHandler DConnected;
        int SataSpeed = 15;
        bool ISata.Connect(){
            if (ISata.speed == SataSpeed){
                Console.WriteLine("Можно подключить");
                DConnected?.Invoke("Sata устройство"); return true;
            }
            else{
                Console.WriteLine("Нельзя подключить"); return false;
            }
        }
    }
    class Printer : IUsbBus{
        public event DConnectHandler DConnected;
        int USBSpeed = 5;
        bool IUsbBus.Connect(){
            if (IUsbBus.speed == USBSpeed){
                Console.WriteLine("Можно подключить");
                DConnected?.Invoke("USB - устройство"); return true;
            }
            else{
                Console.WriteLine("Нельзя подключить"); return false;
            }
        }
    }
    class Scanner : IUsbBus{
        public event DConnectHandler DConnected;
        int USBSpeed = 10;
        bool IUsbBus.Connect()
        {
            if (IUsbBus.speed == USBSpeed)
            {
                Console.WriteLine("Можно подключить");
                DConnected?.Invoke("USB - устройство"); return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить"); return false;
            }
        }
    }
    class NetworkCard : IInnerBus, INetwork{
        public event DConnectHandler DConnected;
        int NetworkSpeed = 20;
        int InnerSpeed = 100;
        bool Program.IInnerBus.Connect(){
            if (IInnerBus.speed == InnerSpeed){
                Console.WriteLine("Можно подключить");
                DConnected?.Invoke("Внутренная шина"); return true;
            }
            else{
                Console.WriteLine("Нельзя подключить"); return false;
            }
        }
        bool Program.INetwork.Connect(){
            if (INetwork.speed == NetworkSpeed){
                Console.WriteLine("Можно подключить");
                DConnected?.Invoke("Сетевое устройство"); return true;
            }
            else{
                Console.WriteLine("Нельзя подключить"); return false;
            }
        }
    }
    class Keyboard : IUsbBus {
        public event DConnectHandler DConnected;
        int USBspeed = 4;
        bool IUsbBus.Connect(){
            if (IUsbBus.speed == USBspeed){
                Console.WriteLine("Можно подключить");
                DConnected?.Invoke("USB - устройство"); return true;
            }
            else{
                Console.WriteLine("Нельзя подключить"); return false;
            }
        }
    }
    static void Main() {
        MotherBoard computer = new MotherBoard();
        Console.WriteLine("/////");
        IUsbBus MB = new MotherBoard();
        IUsbBus USBdevice = new Printer();
        Console.WriteLine("/////");
        Console.WriteLine($"{USBdevice.Connect()} and {MB.Connect()})");
        if (USBdevice.Connect() && MB.Connect() )
        {

        };
        Console.WriteLine("/////");
        ISata sataDevice = new HardDisk();
        INetwork networkCard = new NetworkCard();
        IUsbBus KeyboardRed = new Keyboard();
        Console.WriteLine("/////");

        MotherBoard MainComp = new MotherBoard();
        Console.WriteLine("/////");
        MainComp.DConnected += (deviceName) =>
        {
            Console.WriteLine($"{deviceName} было подключено к материнской плате.");
        };
        Console.WriteLine("/////");
        INetwork networkCard1 = new NetworkCard();
        Console.WriteLine("/////");
        IInnerBus networkCard2 = new NetworkCard(); // создаём объект классаNetworkCard и помещаем
        //if (networkCard1.Connect() && MainComp.Connect())
        //{

        //}
        Console.WriteLine($"{KeyboardRed.Connect()} and {networkCard2.Connect()})"); //networkCard2 просто ссылка?
        if(KeyboardRed.Connect() && networkCard2.Connect())
        {
            Console.WriteLine("Подключены, а как трактовать не могу, и почему не с главным компом");
        }
    }
}