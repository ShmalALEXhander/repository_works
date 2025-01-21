public class Main {
    public static void main(String[] args) { // массив строк
        int x= Integer.parseInt(args[0]);
        System.out.println(x);
        System.out.println(Long.toString(x,2));
        System.out.println(Long.toString(x,8));
        System.out.println(Long.toString(x,16));
    }
}