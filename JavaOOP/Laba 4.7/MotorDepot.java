import java.util.ArrayList;

public class MotorDepot {
    int kolvo = 0;
    int max;
    ArrayList <Integer> stat;
    ArrayList <Car> list = new ArrayList <Car>(max); //инициализация конструктором по умолчанию
    //В каких случаях должна исполняться
    public MotorDepot(int max_) {  //конструктор
        this.max=max_;
        stat = new ArrayList<>(max_);
    }
    public void Add(Passenger a, int status) {
        if(kolvo==max){
            System.out.println("Мест в автобазе нет");
            return;
        }
        list.add(a);
        stat.add(status);
        kolvo++;
    }
    public void Add(Bus a, int status) {
        if(kolvo==max){
            System.out.println("Мест в автобазе нет");
        return;
        }
        list.add(a);
        stat.add(status);
        kolvo++;
    }
    public void Add(Cargo a, int status) {   //Методы не используемые , хотя описанные оказывают минимальное влиние  (память занимает)
        if(kolvo==max){
            System.out.println("Мест в автобазе нет");
            return;
        }
        list.add(a);
        stat.add(status);
        kolvo++;
    }
    public void Add(FireEngine a, int status) {
        if(kolvo==max){
            System.out.println("Мест в автобазе нет");
            return;
        }
        list.add(a);
        stat.add(status);
        kolvo++;
    }
    public void ShowDepot() {
        for (int i = 0; i < stat.size(); i++) {
            if (stat.get(i) == 0)
                System.out.println("Исправен");
        }
    }
    public void SetStatus(int num_, int sost){
        stat.set(num_, sost);
    }
    public void ShowFlight(){
        for (int i = 0; i < stat.size(); i++) {
            if (stat.get(i) == 1)
                System.out.println("В рейсе");
        }
    }
    public void ShowService(){
        for (int i = 0; i < stat.size(); i++) {
            if (stat.get(i) == 2)
                System.out.println("Неисправен");
        }
    }
}
