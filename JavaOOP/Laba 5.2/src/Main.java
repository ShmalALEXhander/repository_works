import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Bag b= new Bag(15);
        Bag c= new Bag(30);
        b.Pop(5);
        b.Push("435s435");
        b.Push("43sdf35");
        b.Push("435");
        b.Push('4');
        b.Push(123);
        b.Push(12.3);
        //b.Size();
       // b.Search(4);
        b.SearchRandom();
        b.Show();
        b.Peretas();
        System.out.println();
        b.Show();
       // b.Pop(3);
        //a.Peretas(Object[] Bag);
       // b.Search(4);
        //b.SearchRandom();
    }
}