using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

[Serializable]
public class MovieSession
{
    public DateTime StartTime { get; set; }
    public string MovieTitle { get; set; }
    public int DurationInMinutes { get; set; }
    public bool[] Seats { get; set; }
}

public class TicketSalesSystem
{
    private List<MovieSession> movieSessions = new List<MovieSession>();

    public void AddMovieSession(DateTime startTime, string movieTitle, int durationInMinutes, int numberOfSeats)
    {
        MovieSession session = new MovieSession
        {
            StartTime = startTime,
            MovieTitle = movieTitle,
            DurationInMinutes = durationInMinutes,
            Seats = new bool[numberOfSeats]
        };

        movieSessions.Add(session);
        Console.WriteLine($"Добавлен новый киносеанс \"{movieTitle}\" на {startTime}. Длительность {durationInMinutes} минут.");
    }

    public void SellTicket(int sessionIndex, int seatNumber){
        if (sessionIndex < 0 || sessionIndex >= movieSessions.Count){
            Console.WriteLine("Неверный индекс сеанса");
            return;
        }

        MovieSession session = movieSessions[sessionIndex];
        if (seatNumber < 0 || seatNumber >= session.Seats.Length){
            Console.WriteLine("Неверный номер места");
            return;
        }

        if (session.Seats[seatNumber]){
            Console.WriteLine("Место уже занято");
        }
        else{
            session.Seats[seatNumber] = true;
            Console.WriteLine($"Билет на сеанс \"{session.MovieTitle}\" продан. Место №{seatNumber + 1}");
        }
    }

    public void SerializeToXml(string fileName)
    {
        XmlSerializer serializer = new XmlSerializer(typeof(List<MovieSession>));
        using (StreamWriter writer = new StreamWriter(fileName))
        {
            serializer.Serialize(writer, movieSessions);
        }

        Console.WriteLine("Состояние системы успешно сериализовано в файл.");
    }

    public void DeserializeFromXml(string fileName)
    {
        XmlSerializer serializer = new XmlSerializer(typeof(List<MovieSession>));
        using (StreamReader reader = new StreamReader(fileName))
        {
            movieSessions = (List<MovieSession>)serializer.Deserialize(reader);
        }

        Console.WriteLine("Состояние системы загружено.");
    }

    public void ReturnTicket(int sessionIndex, int seatNumber){
        if (sessionIndex < 0 || sessionIndex >= movieSessions.Count){
            Console.WriteLine("Неверный индекс сеанса");
            return;
        }
        MovieSession session = movieSessions[sessionIndex];
        if (seatNumber < 0 || seatNumber >= session.Seats.Length){
            Console.WriteLine("Неверный номер места");
            return;
        }
        if (!session.Seats[seatNumber]){
            Console.WriteLine("Место уже свободно");
        }
        else{
            session.Seats[seatNumber] = false;
            Console.WriteLine($"Билет на сеанс \"{session.MovieTitle}\" возвращен в продажу. Место №{seatNumber + 1}");
        }
    }
}

class Program{
    static void Main(){
        TicketSalesSystem ticketSystem = new TicketSalesSystem();

        ticketSystem.AddMovieSession(new DateTime(2022, 8, 15, 18, 0, 0), "Фильм 1", 120, 50);
        ticketSystem.AddMovieSession(new DateTime(2022, 8, 15, 20, 30, 0), "Фильм 2", 90, 60);
        ticketSystem.AddMovieSession(new DateTime(2022, 8, 15, 20, 30, 0), "Фильм 3", 90, 60);
        ticketSystem.AddMovieSession(new DateTime(2022, 8, 15, 20, 30, 0), "Фильм 4", 90, 60);

        bool running = true;
        while (running){
            Console.WriteLine("Выберите действие:");
            Console.WriteLine("1. Продать билет");
            Console.WriteLine("2. Сохранить состояние системы");
            Console.WriteLine("3. Вернуть билет");
            Console.WriteLine("4. Выйти из программы");
            int choice = int.Parse(Console.ReadLine());

            switch (choice){
                case 1:
                    Console.WriteLine("Введите индекс сеанса:");
                    int sessionIndex = int.Parse(Console.ReadLine());
                    Console.WriteLine("Введите номер места:");
                    int seatNumber = int.Parse(Console.ReadLine());

                    ticketSystem.SellTicket(sessionIndex, seatNumber);
                    break;
                case 2:
                    Console.WriteLine("Введите имя файла для сохранения:");
                    string fileName = Console.ReadLine();
                    ticketSystem.SerializeToXml(fileName);
                    break;
                case 3:
                    Console.WriteLine("Введите индекс сеанса для возврата билета:");
                    int sessionIndexReturn = int.Parse(Console.ReadLine());
                    Console.WriteLine("Введите номер места для возврата билета:");
                    int seatNumberReturn = int.Parse(Console.ReadLine());

                    ticketSystem.ReturnTicket(sessionIndexReturn, seatNumberReturn);
                    break;
                case 4:
                    running = false;
                    break;
                default:
                    Console.WriteLine("Неверный выбор. Пожалуйста, введите число от 1 до 4.");
                    break;
            }
        }
    }
}