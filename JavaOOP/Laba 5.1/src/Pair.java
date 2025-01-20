class Pair<T1,T2> { //Пример массив ссылок ( массив объектов). В T1,T2 хранится ссылка.
    public T1 x; //Пространство для хранения адреса или ссылки на переменную.Размер адреса един для всех типов ( 8 байт)
    public T2 y;

    public Pair(T1 x_, T2 y_) { // принимает ссылки на тип
        this.x = x_;
        this.y = y_;
    }
   public T1 getX(){
        return x;
    }
    public T2 getY(){
        return y;
    }
    /*public T getXY(){
        System.out.println(Object.x)
    }*/
   public void setX(T1 x_) { //ограничения задаются с помощью классов и только их ?
       this.x=x_;
   }
   public void setY(T2 y_){  //универсальный параметр для значений
       this.y=y_;
   }
   static Pair<Object,Object> make_pair(Object x_, Object y_) {
       return new Pair<>(x_,y_);
   }

}
