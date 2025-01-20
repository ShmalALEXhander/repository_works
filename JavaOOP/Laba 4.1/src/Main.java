import java.lang.String;
public class Main {
    public static void main(String[] args) {
        Car a=new Car("Марка1",Views.Passenger,"Зелёный",800,4);
        Car b=new Car("Марка2",Views.Passenger,"Серый",900,4);
        Car c=new Car("Марка3",Views.Cargo,"Фиолетовый",1500,10);
        Car d=new Car("Марка4",Views.Passenger,"Красный",840,4);
        Car f=new Car("Марка5",Views.Bus,"Синий",900,8); //как пробежать по циклу
        Car р=new Car("Марка5",Views.Bus,"Синий",900,8,"13123Э");
        c.setRegnum("31313");
        c.setRegnum("А 123 С 654 RUS");
        c.Show();
    }
}