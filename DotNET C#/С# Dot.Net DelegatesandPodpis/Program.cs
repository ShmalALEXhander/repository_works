using System;
class Program
{
    delegate void ReceivedDataEventHandler(string data); // Делегат - указатель на фукцию
    class SourceData //источник данных
    {
        public event ReceivedDataEventHandler ReceivedData;  //событие, объявленное в классе. Где-то фигурирует понятие сигнатуры.
        void OnDataReceived(string data)
        {
            ReceivedData?.Invoke(data); //выполняет делегат, есть перегрузки. //это конкретный звонок
        }
        public void GetData()
        {
            string data = "Устройство подключено";
            OnDataReceived(data);
        }
        //
    }
    class HandlerData
    {
       public void OnDataReceived(string data)
        {
            Console.WriteLine($"Данные получены: {data}");
        }
    }
    static void Main()
    {
        SourceData a = new SourceData();
        HandlerData b = new HandlerData();
        a.ReceivedData += b.OnDataReceived; // OnDataReceived делегат - адрес функции // передача телефона 
        //Имя фукции есть адрес этой функции.
        a.GetData();
        Console.WriteLine("/////////////");
        a.ReceivedData -= b.OnDataReceived;
        a.GetData();
    }
}
