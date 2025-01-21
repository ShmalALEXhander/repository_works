public class Complex{
    double re,im;
    public Complex(double re_,double im_){
        this.re=re_;
        this.im=im_;
    }
    public void ShowAlgebr(){
        System.out.printf("%f+i%f",re,im);
    }
    public void ShowTrig(){
        double r = Math.sqrt(Math.pow(this.re,2) + Math.pow(this.im,2));
        int q0=(int)(Math.toDegrees(Math.atan(Math.abs(im/re))));
        int q = 0;
        if (re == 0 || im == 0) System.out.println("Точка в начале координат");
        if (re > 0) {
            q= im > 0 ? q0 : 360 - q0; // 1 и 4
        } else q = im > 0 ? 180 - q0 : 180 + q0;   // 2 и 3
        System.out.printf("z = %f(cos(%d) + i*sin(%d))",r,q,q);
    }
    public double re() {
        return re;
    }
    public double im() {
        return im;
    }
    public Complex Sum(Complex x){ return new Complex(this.re+x.re,this.im + x.im);}
    public Complex Differ(Complex x){ return new Complex(this.re-x.re,this.im - x.im);}
    //Умножение
    public Complex Multip(Complex x){  //Для чего и как можно ещё оперировать этим типом
        double real=this.re*x.re-this.im*x.im;
        double imeg=this.re*x.im+x.re*this.im;
        return new Complex(real,imeg);
    }
    public Complex MultipD(double x) {
        return new Complex(this.re*x,this.im*x);
    }
    //Деление
    public Complex Division(Complex x){
        double real = (this.re*x.re+this.im*x.im)/(Math.pow(x.re,2)+Math.pow(x.im,2));
        double imeg = (this.im*x.re-this.re*x.im)/(Math.pow(x.re,2)+Math.pow(x.im,2));
        return new Complex(real,imeg);
    }
    public boolean equals(Object x){
        if(x==null) return false;
        if(this.getClass()!=x.getClass()) return false;
        Complex that = (Complex) x;
        return(this.re == that.re) && (this.im == that.im);
    }
    public Complex Conjugate() {
        im= -im;
        return new Complex(re,im);
    }
}