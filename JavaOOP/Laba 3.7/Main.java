import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Введите число для перевода:");
        int x = sc.nextInt();
        System.out.println("Введите основание системы счисления:");
        int osn;
        do {
            osn = sc.nextInt();
        }
        while(osn<2||osn>9);
        int value=x;
        String str="";

        while(x>0){
            str += (char)(x % osn +'0');
            x /= osn;
        }
        for (int i = str.length() - 1; i >= 0; i--) {
            System.out.printf("%c",str.charAt(i)); //!!!!!
        }
        String val = Integer.toString(value,osn);
        System.out.println("\nМетодом toString выдаёт:");
        System.out.println(val);
    }
}