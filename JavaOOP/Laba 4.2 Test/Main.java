public class Main {
    public static void main(String[] args) {
        Complex a = new Complex(14,23);
        Complex b = new Complex(12, 16);
        Complex c= a.Sum(b);
        c.Show();
    }
}