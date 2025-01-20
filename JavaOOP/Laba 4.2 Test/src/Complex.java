public class Complex {
    double a,b;
    public void Show(){
        System.out.printf("%f+i%f",a,b);
    }
    public Complex(double a_,double b_){
        this.a=a_;
        this.b=b_;
    }
    public double getReal(){
        return this.a;
    }
    public double getIm(){
        return this.b;
    }
    public Complex Sum(Complex y){
        return new Complex(this.a+y.a,this.b+y.b);
    }
    public Complex Razn(Complex y){
        return new Complex(this.a-y.a,this.b-y.b);
    }
    /*public Complex Umnoz(Complex y){
        Complex a = this;
        double real = a.re * y.re - a.im * y.im;
        double imag = a.re * y.im + a.im * y.re;
        return new Complex(real, imag);
    }*/
}
