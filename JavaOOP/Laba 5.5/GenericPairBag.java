import java.util.ArrayList;

public class GenericPairBag <T> {
    public T x;
    public T y;
    int max;
    ArrayList<T> Container;
    public GenericPairBag(int max){
        Container = new ArrayList <T>(max);
    }
    public T getX(){return x;}
    public T getY(){return y;}
    public void setX(T x_) { //ограничения задаются с помощью классов и только их ?
        this.x=x_;
    }
    public void setY(T y_){  //универсальный параметр для значений
        this.y=y_;
    }
}
