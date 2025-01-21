import java.util.ArrayList;
public class Bag {
    ArrayList<Object> Bag; // Bag это массив а не 1 объект
    private int size = 0,count = 0;
    Bag(int size){ //должен быть защищён размер мешка и соответственно его инициалзация
        Bag=new ArrayList <Object>();
        this.size=size;
    }
    public Object Pop(int index){ //метод для вывода всего мешка// встряска
        if(count==0)
            return 0;
        count--;
        return Bag.remove(index);
    }
    public Object PopTwo(Object value){ //метод для вывода всего мешка// встряска
        for(Object it: Bag){
            if(it==value){
                return it;
            }
        }
        return -1;
    }
    public Object Push(Object x){
        if(count == this.size)
            return 0;
        count++;
        Bag.add(x);
        return x;
    }
    public int Size(){
        return this.count;
    }
    public Object Search(int index){return Bag.get(index);}
    public Object SearchRandom(){
        int index=(int) (Math.random()* count);
        if(count>index)
        return -1;
        System.out.printf("Возвращён из позиции %d элемент ",index);
        return Bag.get(index);
    }
    public void Peretas() {
        int j;
        for (int i = 0; i < count; i++) {
            j = (int) (Math.random() * count);
            Object tmp = this.Bag.get(i);
            this.Bag.set(i, this.Bag.get(j));
            this.Bag.set(j, tmp);
        }
    }
    public void Show(){
        for(int i=0;i<count;i++){
            System.out.print(Bag.get(i));
            System.out.print(" ");
        }
    }
}
