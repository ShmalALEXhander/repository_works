
public class Main {
    public static void main(String[] args) {
        //Scanner sc = new Scanner(System.in);
        // sc.useLocale(Locale.ENGLISH); // особо не нужна , если не путаться
        double R = Double.parseDouble(args[0]);
        double r = Double.parseDouble(args[1]);
        double x = Double.parseDouble(args[2]);
        double y = Double.parseDouble(args[3]);
        double dist=Math.sqrt(Math.pow(Math.abs(0-x),2)+(Math.pow(Math.abs(0-y),2)));
        if(dist<=r)
            System.out.println("Тревога");
        else if(dist<=R)
            System.out.println("Обнаружен");
        else System.out.println("Не обнаружен"); //программа обрабатывает
    }
}
