import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Введите a");
        double a = sc.nextDouble();
        System.out.println("Введите b");
        double b = sc.nextDouble();
        final int size = 101; //Ключевое финальное слово для объявления констансты.
        double[] x=new double[size];
        double[] y=new double[size];
        double step = (b-a)/(size -1);
        for(int i=0;i<size;i++){
            x[i]=a+i*step;
            y[i]=Math.pow(Math.E,x[i])-Math.pow(x[i],3);
        }
        Integral Obj = new Integral(size,x,y);
        double znach = Obj.Calc();
        System.out.println(znach);
    }
}