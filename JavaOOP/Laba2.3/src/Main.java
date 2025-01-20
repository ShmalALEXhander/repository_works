public class Main {
    public static void main(String[] args) {
       double x = 5.3,y= 4.3;
       double R = 6.5 ,r=4;
       double dist=Math.sqrt(Math.pow(Math.abs(0-x),2)+(Math.pow(Math.abs(0-y),2)));
       if(dist<=r)
           System.out.println("Тревога");
       else if(dist<=R)
           System.out.println("Обнаружен");
       else System.out.println("Не обнаружен");
    }
}
