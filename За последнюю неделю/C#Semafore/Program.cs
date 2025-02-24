using System.Diagnostics;

Console.WriteLine("Введите количество потоков -> ");

int threadSize = Convert.ToInt32(Console.ReadLine());
for (int i = 0; i < threadSize; i++)
{
    Reader reader = new Reader(i);
}
class Reader
{
    static int maxSize = 3;
    static int inputSize = 3; 
    // создаем семафор
    static Semaphore sem = new Semaphore(maxSize, inputSize); // не должен принадлежать какому-то объекту, принадлежит именно классу
    Thread myThread;
    int count = inputSize;// счетчик чтения // Пускаем 3 пользователя
    public Reader(int i)
    {
        myThread = new Thread(Read);
        myThread.Name = $"Читатель {i + 1}";
        myThread.Start();
    }
    public void Read()
    {
        Stopwatch stopWatch = new Stopwatch();
        Stopwatch stopWatch1 = new Stopwatch();
        while (count > 0)
        {
            stopWatch.Start();
            sem.WaitOne();  // ожидаем, когда освободится место
            stopWatch.Stop();

            TimeSpan ts = stopWatch.Elapsed;
            string elapsedTime = String.Format("{0:00}:{1:00}:{2:00}.{3:00}", ts.Hours, ts.Minutes, ts.Seconds, ts.Milliseconds / 10);
            Console.WriteLine(" ");
            Console.WriteLine("RunTime " + elapsedTime);
            Console.WriteLine("///////////////////////////////////////////////////////////");
            Console.WriteLine($"{Thread.CurrentThread.Name} входит в библиотеку");
            Console.WriteLine($"{Thread.CurrentThread.Name} читает");
            Console.WriteLine("///////////////////////////////////////////////////////////");
            Thread.Sleep(10000);
            Console.WriteLine($"{Thread.CurrentThread.Name} покидает библиотеку");
            sem.Release();  // освобождаем место
            count--;
            Console.WriteLine(stopwatch1)
            Thread.Sleep(10000);
        }
    }

}
