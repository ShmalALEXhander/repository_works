using System;

class Program
{
    // Делегат для обработки события подключения
    public delegate void DeviceConnectedEventHandler(string deviceName);

    interface IUsbBus
    {
        public const int speed = 5;
        public const int byteMove = 0;

        bool Connect();
    }
    interface ISata
    {
        public const int speed = 150;
        public const int byteMove = 0;
        bool Connect();
    }
    interface INetwork
    {
        public const int speed = 100;
        public const int byteMove = 0;
        bool Connect();
    }
    interface IInnerBus
    {
        public const int speed = 10000;
        public const int byteMove = 55;
        bool Connect();
    }

    class MotherBoard : IInnerBus, IUsbBus, ISata
    {
        public event DeviceConnectedEventHandler DeviceConnected; // Событие подключения устройства

        int USBSpeed = 3;

        bool Program.IInnerBus.Connect()
        {
            // Реализация метода подключения для внутренней шины
            if(IInnerBus.speed == USBSpeed)
            {
                Console.WriteLine("Можно подключить USB устройство");
                DeviceConnected?.Invoke("USB устройство"); // Вызываем событие
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить USB устройство");
                return false;
            }
        }
        bool Program.IUsbBus.Connect()
        {
            if (IUsbBus.speed == USBSpeed)
            {
                Console.WriteLine("Можно подключить USB устройство");
                DeviceConnected?.Invoke("USB устройство"); // Вызываем событие
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить USB устройство");
                return false;
            }
        }
        bool Program.ISata.Connect()
        {
            // Реализация метода подключения для SATA
            if (ISata.speed == USBSpeed)
            {
                Console.WriteLine("Можно подключить USB устройство");
                DeviceConnected?.Invoke("USB устройство"); // Вызываем событие
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить USB устройство");
                return false;
            }
        }
    }
    class RamMemory : IInnerBus
    {
        void Program.IInnerBus.Connect()
        {
            // Реализация метода подключения для RAM
        }
    }

    class HardDisk : ISata
    {
        void Program.ISata.Connect()
        {
            // Реализация метода подключения для жесткого диска
        }
    }

    class Printer : IUsbBus
    {
        int USBSpeed = 5;

        bool Program.IUsbBus.Connect()
        {
            if (IUsbBus.speed == USBSpeed)
            {
                Console.WriteLine("Можно подключить принтер");
                return true;
            }
            else
            {
                Console.WriteLine("Нельзя подключить принтер");
                return false;
            }
        }
    }

    class Scanner : IUsbBus
    {
        bool Program.IUsbBus.Connect()
        {
            return true; // Предположим, сканер всегда может подключиться
        }
    }

    class NetworkCard : IInnerBus, INetwork
    {
        void Program.IInnerBus.Connect()
        {
            // Реализация метода подключения для сетевой карты
        }

        void Program.INetwork.Connect()
        {
            // Реализация метода подключения для сети
        }
    }

    class Keyboard : IUsbBus
    {
        bool Program.IUsbBus.Connect()
        {
            return false; // Предположим, клавиатура не может подключиться
        }
    }

    static void Main()
    {
        MotherBoard computer = new MotherBoard();

        // Подписываемся на событие
        computer.DeviceConnected += (deviceName) =>
        {
            Console.WriteLine($"{deviceName} было подключено к материнской плате.");
        };

        IUsbBus MB = computer; // Теперь используем экземпляр материнской платы
        IUsbBus USBdevice = new Printer();

        if (USBdevice.Connect() && MB.Connect())
        {
            // Дополнительная логика, если нужно
        }

        ISata sataDevice = new HardDisk();
        INetwork networkCard = new NetworkCard();
    }
}