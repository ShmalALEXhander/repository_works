import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
public class DList<T1,T2> {
    int size;
    List<T1> list1 ;
    List<List<T2>> list2;
    public DList(){
        list1 = new ArrayList<T1>();
        list2 = new ArrayList<List<T2>>();//возвращает ссылку на память
    }
    public DList(T1 x,List<T2> y) {
        //list1 = new ArrayList<T1>();
        list1 = new ArrayList<T1>();
        list2 = new ArrayList<List<T2>>();//возвращает ссылку на память
        list1.add(x);
        list2.add(y);
        //list2 = new ArrayList<List<T2>>();//возвращает ссылку на память
    }
    public void Push(T1 x,List<T2> y){
        list1.add(x);
        list2.add(y);
    }
    public void PopInd(int index){
        list1.remove(index);
        list2.remove(index);
    }
    public void PopVal(T1 x){
        for(int i=0;i<list1.size();i++){
            if(x== list1.get(i)){
                list1.remove(i);
                list2.remove(i);
            }
        }
    }
    public DList<T1,T2> getInd(int index){
        return new DList( list1.get(index),list2.get(index));
    } //Для того что вернуть объект из нескольких объектов требуется вызвать конструктор этого листа
    public DList<T1,T2> getVal(Object value){
        int tmp = -1;
        for(int i = 0; i <list1.size(); i++){
            if(list1.get(i)==value) {
                tmp = i;
                break;
            }
        }
        if(tmp!=-1)
        return new DList(list1.get(tmp),list2.get(tmp));
        return new DList(0, Arrays.asList(0));
    }
    public void printList() {
        for(int i = 0; i <list1.size();i++){
        System.out.print(list1.get(i));
        System.out.print(" ");
        System.out.println(list2.get(i));
        }
    }
}
