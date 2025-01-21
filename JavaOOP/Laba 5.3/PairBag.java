import java.util.ArrayList;

public class PairBag extends Bag {
    ArrayList<Pair<Object,Object>> BagPair;
    int size;
    int count=0;
    public PairBag(int size){
        super(size); //вызвали конструктор
        BagPair=new ArrayList <Pair<Object,Object>>(size);
            this.size=size;
    }//Оверрайд не нужен
    public boolean Push(Pair<Object,Object> x) {
        if(count == this.size)
            return false;
        count++;
        BagPair.add(x);
        return true;
    }
    public void Show(){ //
        for(int i=0;i<count;i++){
            System.out.print(BagPair.get(i).x);
            System.out.print(" ");
            System.out.print(BagPair.get(i).y);
            System.out.print(" ");
        }
    }
   // public Object Search(int index){return Bag.get(index);}
}
