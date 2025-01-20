import java.util.regex.Matcher;
import java.util.regex.Pattern;//Наследники не знаю что они принадлежат классу Car

public class Car {
    String Brand;
    String Color;
    private Engine Engine;
    public void Show(){
        System.out.printf("Бренд: %s",this.Brand);
        System.out.printf("Цвет: %s",this.Color);
        Engine.Show();
    }
    public Car(String Brand_,String Color_, Engine Engine_){
        this.Brand=Brand_;
        this.Color=Color_;
        this.Engine= Engine_;
    }
}//  При наследовании объект производного класса не знает откуда он был унаследован
class Passenger extends Car{
    String RegNum;
    int WheelNum = 4;
    public boolean ControlRegnum(String Regnum_) {
        //X_000_XX_00_RUS   0 -цифры - Х - буквы
        //X_000_XX_000_RUS
        //Pattern pattern = Pattern.compile("^[АВЕКМНОРСТУХ]\\D\\s\\d{3}\\s\\D[АВЕКМНОРСТУХ]{2}\\s\\d{2,3}\\sRUS$");
        Pattern pattern = Pattern.compile("^\\D\\s\\d{3}\\s\\D{2}\\s\\d{2,3}\\s$");
        Matcher m = pattern.matcher(Regnum_);//в m лежит объект класса matcher
        return m.matches();
    }
    public void setRegNum(String RegNum_){
        if(ControlRegnum(RegNum_)==true)
            this.RegNum=RegNum_;
        else System.out.println("Неверный регистрационный номер!!!");
    }
    public void Show(){
        super.Show(); //вызвали из родительского класса (является общим)
        System.out.printf(" Рег.Номер: %s",this.RegNum);
        System.out.printf(" Кол-во колёс: %s",this.WheelNum);
        System.out.println();
    }
    public Passenger(String Brand_,String Color_, Engine Engine_,String RegNum_){
        super(Brand_,Color_,Engine_);
        this.RegNum=RegNum_;
    }
}
class Cargo extends Car{
    String RegNum;
    int WheelNum = 10;
    public boolean ControlRegnum(String Regnum_) {
        //X_000_XX_00_RUS   0 -цифры - Х - буквы
        //X_000_XX_000_RUS
        //Pattern pattern = Pattern.compile("^[АВЕКМНОРСТУХ]\\D\\s\\d{3}\\s\\D[АВЕКМНОРСТУХ]{2}\\s\\d{2,3}\\sRUS$");
        Pattern pattern = Pattern.compile("^\\D{2}\\s\\d{3}\\s\\D{2}\\s\\d{2,3}\\s$");
        Matcher m = pattern.matcher(Regnum_);//в m лежит объект класса matcher
        return m.matches();
    }
    public void Show(){
        super.Show(); //вызвали из родительского класса (является общим)
        System.out.printf(" Рег.Номер: %s",this.RegNum);
        System.out.printf(" Кол-во колёс: %s",this.WheelNum);
        System.out.println();
    }
    public void setRegNum(String RegNum_){
        if(ControlRegnum(RegNum_)==true)
            this.RegNum=RegNum_;
        else System.out.println("Неверный регистрационный номер!!!");
    }
    public Cargo(String Brand_,String Color_, Engine Engine_,String RegNum_){
        super(Brand_,Color_,Engine_);
        this.RegNum=RegNum_;
    }
}
final class Bus extends Car{
    String RegNum;
    int WheelNum = 8;
    public boolean ControlRegnum(String Regnum_) {
        //X_000_XX_00_RUS   0 -цифры - Х - буквы
        //X_000_XX_000_RUS
        //Pattern pattern = Pattern.compile("^[АВЕКМНОРСТУХ]\\D\\s\\d{3}\\s\\D[АВЕКМНОРСТУХ]{2}\\s\\d{2,3}\\sRUS$");
        Pattern pattern = Pattern.compile("^\\D{3}\\s\\d{3}\\s\\D{2}\\s\\d{2,3}\\s$");
        Matcher m = pattern.matcher(Regnum_);//в m лежит объект класса matcher
        return m.matches();
    }
    public void setRegNum(String RegNum_){
        if(ControlRegnum(RegNum_))
            this.RegNum=RegNum_;
        else System.out.println("Неверный регистрационный номер!!!");
    }
    public void Show(){
        super.Show(); //вызвали из родительского класса (является общим)
        System.out.printf(" Рег.Номер: %s",this.RegNum);
        System.out.printf(" Кол-во колёс: %s",this.WheelNum);
        System.out.println();
    }
    public Bus(String Brand_,String Color_, Engine Engine_,String RegNum_){
        super(Brand_,Color_,Engine_);
        this.RegNum=RegNum_;
    }
}
class FireEngine extends Car{
    String RegNum;
    int WheelNum = 6;
    public boolean ControlRegnum(String Regnum_) {
        //X_000_XX_00_RUS   0 -цифры - Х - буквы
        //X_000_XX_000_RUS
        //Pattern pattern = Pattern.compile("^[АВЕКМНОРСТУХ]\\D\\s\\d{3}\\s\\D[АВЕКМНОРСТУХ]{2}\\s\\d{2,3}\\sRUS$");
        Pattern pattern = Pattern.compile("^\\D{4}\\s\\d{3}\\s\\D{2}\\s\\d{2,3}\\s$");
        Matcher m = pattern.matcher(Regnum_);//в m лежит объект класса matcher
        return m.matches();
    }
    public void setRegNum(String RegNum_){
        if(ControlRegnum(RegNum_))
            this.RegNum=RegNum_;
        else System.out.println("Неверный регистрационный номер!!!");
    }
    public void Show(){
        super.Show(); //вызвали из родительского класса (является общим)
        System.out.printf(" Рег.Номер: %s",this.RegNum);
        System.out.printf(" Кол-во колёс: %s",this.WheelNum);
        System.out.println();
    }
    public FireEngine(String Brand_,String Color_, Engine Engine_,String RegNum_){
        super(Brand_,Color_,Engine_);
        this.RegNum=RegNum_;
    }
}