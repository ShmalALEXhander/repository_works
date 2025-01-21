class Program
{
    static void BubbleSort(int[] arr)
    {
        int tmp;
        int size = arr.Length;
        //Сортирвка пузырьком
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }
    static void Main()
    {
        // Должна быть строка, в которую запишем все элементы массивы
        //Можем провести конвертацию строки не строки, чтобы не заморачиваться, а провести конвертацию уже собранного массива string в массив int
        // И его отсортировать
        //Вывести результат             
        Console.WriteLine("Введите элементы массива через пробелы");
        string input = Console.ReadLine();
        string[] massSTR = input.Split(' ');
        try
        {
            int[] massINT = Array.ConvertAll(massSTR, int.Parse); // Некий источник исключения
            BubbleSort(massINT);
            Console.WriteLine("Отсортированный массив: \n" + string.Join(" ", massINT));
        }
        catch (FormatException) // аргумент - класс
        {
            Console.WriteLine("Ошибка: Ввод должен содержать только целые числа");
        }
        catch (OverflowException)
        {
            Console.WriteLine("Ошибка: Одно из введенных чисел слишком велико или слишком мало для типа int.");
        }
        catch (Exception ex) // объект класса
        {
            Console.WriteLine($"Произошла ошибка: {ex.Message}");
        }

        //Конвертированный элементы отсортировал и они остались в массиве.
    }
}