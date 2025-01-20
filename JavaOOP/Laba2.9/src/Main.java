import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        while(true){
        Scanner sc = new Scanner(System.in);  //как сделать чтобы оно было вечным по примеру while (true)
        System.out.println("Введите строку для нахождения вхождений ");
        String str = sc.nextLine();
        System.out.println("Введите строку для поиска ");
        String searchSTR = sc.nextLine();
        int chet = 0;
        int value = str.indexOf(searchSTR); // должен быть первичный поиск в любом случае
        while(value!=-1){
            value = str.indexOf(searchSTR,value+1);
            chet++;
       }
        System.out.println("Количество вхождений ");
        System.out.println(chet);
        sc.close(); //Вывел из области видимости . While (true) - отдельный блок.
        }
    }
}