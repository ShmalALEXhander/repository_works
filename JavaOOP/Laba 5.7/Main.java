import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        DList<Object,Object> c = new DList<Object, Object>(1, List.of(2, 3, 4));


        List<List<Integer>> lists = Arrays.asList(Arrays.asList(1, 2, 3),
                Arrays.asList(4, 5, 6),
                Arrays.asList(6, 7, 8));
        c.Push(15, List.of(12,13,14));
        c.Push(20, Arrays.asList(Arrays.asList(1, 2, 3), //Формирует лист из листов
                Arrays.asList(4, 5, 6),
                Arrays.asList(6, 7, 8)));
        System.out.println("All");
        c.printList();
        System.out.println("-----------");
       // DList<Object,Object> tmp=c.getInd(2);
        //tmp.printList();
        System.out.println("-----------");
        c.PopVal(15);
        DList<Object,Object> tmp=c.getVal(20);
        tmp.printList();
        DList<Object,Object> tmp1=c.getVal(2);
        tmp1.printList();
        System.out.println("-----------");
        //c.PopInd(2);
       // c.printList();
    }
}