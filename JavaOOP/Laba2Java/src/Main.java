
public class Main {
    public static void main (String []args){
        Mass array = new Mass();
        double sg = 1.0;
        int n=0;
        for(int i=0;i<20;i++){
            if (array.arr[i] <0) { n++; sg*=array.arr[i]; };
        }
        array.Show();
        double res=Math.pow(Math.abs(sg),1.0/n);
        System.out.println(res);               //Вывод с переводом строки
    }
}