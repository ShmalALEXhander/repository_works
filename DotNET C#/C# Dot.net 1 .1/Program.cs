
class Program
{
    static void InsertSort(int[] arr)
    {
        int size = arr.Length; // нет гаранти что это метод, т.к. может быть вычисляемой величиной
        // Из раздела Темы"Коллекции"
        for (int i = 0; i < size; i++)
        {
            int j = i;
            int x = arr[i];
            while ((j > 0) && (arr[j - 1] > x))
            {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = x;
        }
    }
    static void Main()// Точка ВХОДА, с большой буквы // не привязан к конкретному объекту. Отличается от static в С++. (С#) Program.Main() - для вызова
    {
        // Должна быть строка, в которую запишем все элементы массивы
        //Можем провести конвертацию строки не строки, чтобы не заморачиваться, а провести конвертацию уже собранного массива string в массив int
        // И его отсортировать
        //Вывести результат
        //Конвертированный элементы отсортировал и они остались в массиве.
        Console.WriteLine("Введите элементы массива через пробелы");
        string input = Console.ReadLine(); // Вообще всегда (почти всегда) работают с объектами, ведь класс это тип, а с ним не работают
        string[] massSTR = input.Split(' ');
        try
        {
            int[] massINT = Array.ConvertAll(massSTR, int.Parse);// посмотри внимательно
            InsertSort(massINT);
            Console.WriteLine("Отсортированный массив: \n" + string.Join(" ", massINT));
        }
        catch (FormatException)
        {
            Console.WriteLine("Ошибка: Ввод должен содержать только целые числа.");
        }
        catch (OverflowException)
        {
            Console.WriteLine("Ошибка: Одно из введенных чисел слишком велико или слишком мало для типа int.");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Произошла ошибка: {ex.Message}");
        }
        finally
        {
            Console.WriteLine("Поздравляю!!!");
        }
    }
}
