public class Engine {

    int FactNum;// Заводской номер
    int Power;//Мощность
    int WorkVolume;// рабочий объём
    int FuelConsum;// расход топлива
    Topl TypeFuel; // вид топлива
    int NumCil; //число цилиндров

    public Engine(int Power_, int WorkVolume_, int FuelConsum_, Topl TypeFuel_, int NumCil_) {
        this.Power = Power_;
        this.WorkVolume = WorkVolume_;
        this.FuelConsum = FuelConsum_;
        this.TypeFuel = TypeFuel_;
        this.NumCil = NumCil_;
    }

    public Engine(int FactNum_, int Power_, int WorkVolume_, int FuelConsum_, Topl TypeFuel_, int NumCil_) {
        this.FactNum = FactNum_;
        this.Power = Power_;
        this.WorkVolume = WorkVolume_;
        this.FuelConsum = FuelConsum_;
        this.TypeFuel = TypeFuel_;
        this.NumCil = NumCil_;
    }

    public void Show() {
        System.out.printf("Заводской номер: %s", this.FactNum);
        System.out.printf(" Мощность %d: ", this.Power);
        System.out.printf("Рабочий объём %d: ", this.WorkVolume);
        System.out.printf("Расход обьём: %s ", this.FuelConsum);
        System.out.print("Вид двигателя: ");
        if (this.TypeFuel == Topl.GreenSteam) {
            System.out.print(" GreenSteam");
        } else if (this.TypeFuel == Topl.Vtip) {
            System.out.print(" Vtip");
        } else if (this.TypeFuel == Topl.Radical) {
            System.out.print(" Radical");
        } else System.out.println("100");
        System.out.printf(" Число цилиндров: %d", this.NumCil);
    }
}
enum Topl {
    GreenSteam,
    Vtip,
    Radical
}

