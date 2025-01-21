public class Integral {
    double[] x;
    double[] y;
    int size;
    public Integral(int size_,double[] x, double[] y){
        this.size=size_;
        this.x=new double[size_];
        this.y=new double[size_];
       for(int i=0;i<size_;i++){
           this.x[i]=x[i];
           this.y[i]=y[i];
       }
    }
    public double Calc(){
        double step=this.x[1]-this.x[0];
        double sum=0;
        for(int i=1;i<this.size;i++){
            sum += step*this.y[i];
        }
        return sum;
    }
}
