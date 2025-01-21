//Дан массив из 20 целых переменных. Конкретные значения
//для элементов задаются в конструкции инициализации. Найти среднее
//геометрическое отрицательных элементов.
public class Mass { //конструктор
    int[] arr ;
    public Mass() {
        arr= new int[20];
        for(int i=0;i<20;i++){ //сбрасывает
            arr[i]=(int)(Math.random()*((100-20+1)) -50);
        }
    }
    public void Show() {
        for (int i=0; i<20; i++){
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println("");
    }
}