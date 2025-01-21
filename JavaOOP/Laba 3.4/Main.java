import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("R1 => ");
        double R1 = sc.nextInt();
        System.out.println("\t");
        System.out.println("x1 => ");
        double x1 = sc.nextInt();
        System.out.println("\t");
        System.out.println("y1 => ");
        double y1 = sc.nextInt();
        System.out.println("\t");
        System.out.println("R2 => ");
        double R2 = sc.nextInt();//Идеологически делается именно так. Конструктор создаем когда класс имеет внутренние переменные. Бёрн Страуступ. Вайсфельд Объектно-ориентированное мышление
        System.out.println("\t");
        System.out.println("x2 => ");
        double x2 = sc.nextInt();
        System.out.println("\t");
        System.out.println("y2 => ");
        double y2 = sc.nextInt();
        System.out.println("\t");
        Rounds T = new Rounds(x1,y1,R1,x2,y2,R2); //Строго в такой последовательности
        // T.x1=10; // Взяли объект T  напрямую обратились к полю и занесли в его значение. С точки зрения чистоты программирования нельзя делать так.
        int res=T.check();
        switch (res) {
            case (1):
                System.out.println("Окружность 1 вложена в окружность 2");
                break;
            case (2):
                System.out.println("Окружность 2 вложена в окружность 1");
                break;
            case (3):
                System.out.println("Вообще не пересекаются");
                break;
            case (4):
                System.out.println("Пересекаются в 1 точке");
                break;
            case (7):
                System.out.println("Окружности совпадают по радиусу");
                break;
            case (8):
                System.out.println("Радиусы одинаковы");
                break;
        }
    }
} // геттер и сеттер