public class Main {
    public static void main(String[] args) {
        //String Brand_,String Color_, Engine Engine_,String RegNum_
        Engine dvig1= new Engine(13424,23,4,5,Topl.Vtip, 6);
        Engine dvig2= new Engine(134534,53,4,5,Topl.Vtip, 6);
        Engine dvig4= new Engine(143534,123,8,5,Topl.Radical, 6);
        Engine dvig5= new Engine(1345453,673,9,5,Topl.GreenSteam, 6);
        Passenger c = new Passenger("Марка1","Red", dvig2,"");
        c.Show();
        Passenger b = new Passenger("Марка2","Red23", dvig4,"  ");
        b.Show();
    }
}