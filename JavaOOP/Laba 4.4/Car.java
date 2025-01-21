import java.util.regex.Matcher;
import java.util.regex.Pattern;
enum Views {
    Passenger,
    Cargo,
    Bus
};
public class Car {
    private String Regnum; //регистрационный знак
    private String Brand; //Brand
    private Views View; // Вид
    private String Color;// Цвет          Значения полей класса мы не меняем, благадоря сеттерам мы меняем значения полей объекта
    private Engine Engine; //Мощность двигателя
    private int NumWheels; // количество колёс.

    public boolean ControlRegnum(String Regnum_) {
        //X_000_XX_00_RUS   0 -цифры - Х - буквы
        //X_000_XX_000_RUS
        //Pattern pattern = Pattern.compile("^[АВЕКМНОРСТУХ]\\D\\s\\d{3}\\s\\D[АВЕКМНОРСТУХ]{2}\\s\\d{2,3}\\sRUS$");
        Pattern pattern = Pattern.compile("^\\D[АВЕКМНОРСТУХ]\\s\\d{3}\\s\\D[АВЕКМНОРСТУХ]{2}\\s\\d{2,3}\\sRUS$");
        Matcher m = pattern.matcher(Regnum_);//в m лежит объект класса matcher
        return m.matches();
    }
    public Car(String Brand_,Views View_, String Color_, Engine s_, int NumWheels_) {  //Передаётся объект
        this.Brand = Brand_;
        this.View = View_;
        this.Color = Color_;
        this.Engine = s_;
        this.NumWheels = NumWheels_;
    }
    public Car(String Brand_,Views View_, String Color_, Engine s_, int NumWheels_, String Regnum_) {
        this.Brand = Brand_;
        this.View = View_;
        this.Color = Color_;
        this.Engine = s_;
        this.NumWheels = NumWheels_;
        if(ControlRegnum(Regnum_)==true)
            this.Regnum=Regnum_;
        else System.out.println("При создании машины указан неверный регистрационный номер");
    }
    public void setRegnum(String Regnum_){
        if(ControlRegnum(Regnum_)==true)
            this.Regnum=Regnum_;
        else System.out.println("Неверный регистрационный номер!!!");
    }
    public void setBrand(String Brand_){
        this.Brand=Brand_;
    }
    public void setColor(String Color_){
        this.Color=Color_;
    }
    public void Show(){
        System.out.printf("Бренд: %s",this.Brand);
        System.out.println(" Вид:");
        if(this.View==Views.Passenger){System.out.println(" Легковой");}
        else if(this.View==Views.Cargo){System.out.println(" Грузовой");}
        else if(this.View==Views.Bus){System.out.println(" Автобус");}
        else System.out.println("100");
        System.out.printf("Цвет: %s",this.Color);
       // System.out.printf(" Мощность: %d",this.Engine);
        System.out.printf(" Кол-во колёс: %d ",this.NumWheels);
    }
}