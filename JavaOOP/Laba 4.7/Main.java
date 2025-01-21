import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        //String Brand_,String Color_, Engine Engine_,String RegNum_
        Engine dvig1= new Engine(13424,23,4,5,Topl.Vtip, 6);
        Engine dvig2= new Engine(134534,53,4,5,Topl.Vtip, 6);
        Engine dvig4= new Engine(143534,123,8,5,Topl.Radical, 6);
        Engine dvig5= new Engine(1345453,673,9,5,Topl.GreenSteam, 6);
        Passenger c = new Passenger("Марка1","Red", dvig2,"");
        Passenger b = new Passenger("Марка2","Red23", dvig4,"  ");
        Bus d = new Bus("Марка2","Red23", dvig4,"  ");
        Cargo f = new Cargo("Марка23","blue23", dvig5,"  ");
        FireEngine g = new FireEngine("Ма213рка23","Brown", dvig5,"  ");
        MotorDepot num1 =new MotorDepot(10);
        num1.Add(c,0);
        num1.Add(c,1);
        num1.Add(d,1);
        num1.ShowDepot();
        //
    }
}