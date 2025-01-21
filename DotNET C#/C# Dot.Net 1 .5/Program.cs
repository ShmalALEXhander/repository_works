using System.Reflection;

class Program
{
    static void BubbleSort(string[] mass) // Ссылка С# и ссылка С++ имеют различия. Работа с ссылками   и и значениями. Массивы всегда ссылочные типы.
    {
        int size = mass.Length;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (mass[j].Length > mass[j + 1].Length)
                {
                    string tmp = mass[j];
                    mass[j] = mass[j + 1];
                    mass[j + 1] = tmp;
                }
            }
        }
    }
    //String[] args только для командной строки
    static void Main()
    {
        Console.WriteLine("Введите строку для записи в массив");
        try
        {
            string input = Console.ReadLine();
            string[] massSTR = input.Split(' ');
            // Это для проверки исключения, нелогичный фрагмент кода который не нужен для уже выполненной правильно работы.
            try
            {
                Array intArray = Array.CreateInstance(typeof(int), 5);
                string[] massSTR2 = { "Hello", "World" };             
                Array.Copy(massSTR2, intArray, massSTR2.Length);
            }
            catch (ArrayTypeMismatchException)
            {
                Console.WriteLine("Тип сохраняемого в массив значения несовместим в типом элементов массива!!!");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Произошла ошибка: {ex.Message}");
            }
            //
            Console.WriteLine("Введены следующие элементы: \n");
            foreach (string tmp in massSTR) // Итератор tmp (str)
            {
                Console.WriteLine(tmp); // тут пойдёт str
            }
            BubbleSort(massSTR); // Сортировка может принять на вход и стринг,
                                 //главное оперировать в итоге числами(цифрами)       
            Console.WriteLine("\nПосле сортировки: \n" + string.Join(" ", massSTR));
        }
        catch (OverflowException)
        {
            Console.WriteLine("Ошибка: Одно из введенных чисел слишком велико или слишком мало для типа string."); //неактуально т.к. string может хранить 4 гб и расширяем...
        }
        catch (Exception ex) {
            Console.WriteLine("Прозошла ошибка: {ex.Message}");
        }
    }
}
