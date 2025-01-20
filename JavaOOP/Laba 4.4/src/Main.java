import java.lang.String;
public class Main {
    public static void main(String[] args) {
        //(int Num_,int Power_,int V_, int rashod_,Topl ViewTopl_,int NumCil_)
        Engine dvig1= new Engine(13424,23,4,5,Topl.Vtip, 6);
        Engine dvig2= new Engine(134534,53,4,5,Topl.Vtip, 6);
        Engine dvig4= new Engine(143534,123,8,5,Topl.Radical, 6);
        Engine dvig5= new Engine(1345453,673,9,5,Topl.GreenSteam, 6);
        Car a=new Car("Марка1",Views.Passenger,"Зелёный",dvig1,4);
        Car b=new Car("Марка2",Views.Passenger,"Серый",dvig2,4);
        Car c=new Car("Марка3",Views.Cargo,"Фиолетовый",dvig4,10);
        Car d=new Car("Марка4",Views.Passenger,"Красный",dvig2,4);
        Car f=new Car("Марка5",Views.Bus,"Синий",dvig5,8); //как пробежать по циклу
        c.setRegnum("31313");
        c.setRegnum("А 123 С 654 RUS");
        c.Show();
        dvig4.Show();
    }
}
