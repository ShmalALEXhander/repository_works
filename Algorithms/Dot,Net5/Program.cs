using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class UniqueNumbersEnumerable : IEnumerable
{
	private string inputString;

	public UniqueNumbersEnumerable(string inputString)
	{
		this.inputString = inputString;
	}

	public IEnumerator GetEnumerator()
	{
		var uniqueNumbers = inputString.Split(' ')
			.Where(s = > int.TryParse(s, out _)) // Фильтр чисел
			.Select(s = > int.Parse(s)) // Преобразование строки в число
			.Distinct() // Удаление повторяющихся чисел
			.OrderByDescending(s = > s); // Сортировка по убыванию

		return uniqueNumbers.GetEnumerator();
	}

	IEnumerator IEnumerable.GetEnumerator()
	{
		return GetEnumerator();
	}
}

public class Program
{
	public static void Main(string[] args)
	{
		string inputString = "5 2 3 4 2 5 1 3";
		var uniqueNumbers = new UniqueNumbersEnumerable(inputString);

		foreach (var number in uniqueNumbers)
		{
			Console.WriteLine(number);
		}
	}
}