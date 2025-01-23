public class Complex {
  public double re;
  public double im;
    public Complex(double real, double imag){
        this.re=real;
        this.im=imag;
    }
    //Метод для сложения
    public Complex plus(Complex b) {
       // Complex a = this; this - указатель на собственный класс, на самого себя
        double real = this.re + b.re;
        double imag = this.im + b.im;
        return new Complex(real, imag);
    }
    //Метод для вычитания
    public Complex minus(Complex b) {
       // Complex a = this;
        double real = this.re - b.re;
        double imag = this.im - b.im;
        return new Complex(real, imag);
    }
    //a+bi и c+di
    //(ac - bd) + (bc + ad)i
    //Метод для умножения
    public Complex multiply(Complex b) {
        //Complex a = this;
        double real = (this.re * b.re) - (this.im * b.im);
        double imag = (this.im * b.re) + (this.re * b.im);
        return new Complex(real, imag);
    }
    public Complex times(Complex b) {
        //Complex a = this;
        double real = this.re * b.re - this.im * b.im;
        double imag = this.re * b.im + this.im * b.re;
        return new Complex(real, imag);
    }
    public Complex reciprocal() {
        double scale = re * re + im * im;
        return new Complex(re / scale, -im / scale);
    }
    public Complex division(Complex b){
        Complex a = this;
        return a.times(b.reciprocal());
    }
    //Метод для возведения в степень
    double re (){
        return re;
    }
    double im (){
        return im;
    }
    public static Complex plus(Complex a, Complex b){
        double real = a.re + b.re;
        double imag= a.im + b.im;
        return new Complex(real,imag);
    }
    public String toString() {
        if (im == 0) return re + "";
        if (re == 0) return im + "i";
        if (im < 0) return re + " - " + (-im) + "i";
        return re + " + " + im + "i";
    }
    public static void main(String[] args) {
        Complex F = new Complex(5,4); // Отличие объявление как массива от просто Complex
        Complex M = new Complex(8,6);
        Complex l = new Complex(2,3);
        Complex h;
        h=new Complex(2,3);
        F.plus(M);
        F.toString();
        l.multiply(F);
        l.division(l);
        F.toString();
    }
}