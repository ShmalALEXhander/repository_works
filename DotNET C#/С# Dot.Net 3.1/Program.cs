class Program
{
    interface IUsbBus
    { // он есть, интерфейс мы не создаём.
        public const int speed = 5;
        public const int byteMove = 0;
        bool Connect();
    }
    interface ISata
    { // он есть, интерфейс мы не создаём.
        public const int speed = 150;
        public const int byteMove = 0;
        bool Connect();
    }
    interface INetwork
    { // он есть, интерфейс мы не создаём.
        public const int speed = 500;
        public const int byteMove = 0;
        bool Connect();
    }
    interface IInnerBus
    { // он есть, интерфейс мы не создаём.
        public const int speed = 10000;
        public const int byteMove = 55;
        bool Connect();
    }
    class MotherBoard : IInnerBus, IUsbBus, ISata
    {
        int USBSpeed = 3;
        bool Program.IInnerBus.Connect() {
            if (IInnerBus.speed == USBSpeed)
            {
                Console.WriteLine("Можно подключить");
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить");
                return false;
            }
        }
        bool Program.IUsbBus.Connect()
        {
            if (IUsbBus.speed == USBSpeed)
            {
                Console.WriteLine("Можно подключить");
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить");
                return false;
            }
        }
        bool Program.ISata.Connect()
        {
            if (ISata.speed == USBSpeed)
            {
                Console.WriteLine("Можно подключить");
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить");
                return false;
            }
        }

    }
    class RamMemory : IInnerBus
    {
        int InnerSpeed = 10;
        bool Program.IInnerBus.Connect()
        {
            if (ISata.speed == InnerSpeed)
            {
                Console.WriteLine("Можно подключить");
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить");
                return false;
            }
        }
    }
    class HardDisk : ISata
    {
        int SataSpeed = 15;

        bool Program.ISata.Connect(){
            if (ISata.speed == SataSpeed){
                Console.WriteLine("Можно подключить");
                return true;
            }
            else{
                Console.WriteLine("Нельзя подключить");
                return false;
            }
        }
    }
    class Printer : IUsbBus
    {
        int USBSpeed = 5;
        bool Program.IUsbBus.Connect()
        {
            if (IUsbBus.speed == USBSpeed){
                Console.WriteLine("Можно подключить");
                return true;
            }
            else{
                Console.WriteLine("Нельзя подключить");
                return false;
            }
        }
    }
    class Scanner : IUsbBus
    {
        int USBSpeed = 5;
        bool Program.IUsbBus.Connect()
        {
            if (IUsbBus.speed == USBSpeed)
            {
                Console.WriteLine("Можно подключить");
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить");
                return false;
            }
        }
    }
    class NetworkCard : IInnerBus, INetwork
    {
        int NetworkSpeed = 20;
        bool Program.IInnerBus.Connect()
        {
            if (IInnerBus.speed == NetworkSpeed)
            {
                Console.WriteLine("Можно подключить");
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить");
                return false;
            }
        }
        bool Program.INetwork.Connect()
        {
            if(INetwork.speed == NetworkSpeed)
            {
                Console.WriteLine("Можно подключить");
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить");
                return false;
            }
        } 
    }
    class Keyboard : IUsbBus
    {
        int USBspeed = 4;
        bool Program.IUsbBus.Connect() {
            if (IUsbBus.speed == USBspeed)
            {
                Console.WriteLine("Можно подключить");
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить");
                return false;
            }
        }
}

    static void Main() {
        MotherBoard computer = new MotherBoard();

        IUsbBus MB = new MotherBoard();
        IUsbBus USBdevice = new Printer();

        if (USBdevice.Connect() && MB.Connect())
        {

        };
        ISata sataDevice = new HardDisk();
        INetwork networkCard = new NetworkCard();
    }

}