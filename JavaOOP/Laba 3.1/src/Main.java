public class Main {
    public static void main(String[] args) {
        double pi=3.1415926;
        double y1;
        double y2;
       for(double step=pi/15;step<pi;step+=pi/15) {
           System.out.printf("%10.5f  ",step);
           y1=Math.sin(step);
           System.out.printf("%15.7e  ",y1);
           y2=Math.exp(step)/(step*Math.log(step));
           System.out.printf("%15.7e\n",y2);
       }
    }
}