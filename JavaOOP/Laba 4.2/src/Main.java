public class Main {
    public static void main(String[] args) {
//Объект есть составная переменна ( но может содержать и 1 поле с единственным типомм
        Complex a = new Complex(5,3);
        Complex c= a.Sum(a);
        c.ShowTrig();
    }
}