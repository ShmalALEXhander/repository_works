public class Rounds {
    public double x1,x2,y1,y2,R1,R2; //Должен иметь доступ только сам класс и никто другой (инкапсуляция данных) - такова идеология.
    public Rounds(double x1_,double y1_,double R1_,double x2_,double y2_,double R2_){ // Суть ООП - защита от программиста.
        this.x1=x1_;
        this.y1=y1_;
        this.R1=R1_;
        this.x2=x2_;
        this.y2=y2_;
        this.R2=R2_; //Конструктор инициализции создан
    }
    public int check(){
        double d;
        if((x2==x1)&&(y2==y1)){
            d=0;
            System.out.println("Окружности имеют единый центр");
            if(R2>R1){
                return 1;
            }
            else if(R2<R1){
                return 2;
            }
            else if(R2==R1){
                return 7;
            }
        }
        else if(x2==x1 && y2!=y1){
            d=Math.abs(y2-y1);
        }
        else if(y2==y1 && x2!=x1){
            d=Math.abs(x2-x1);
        }
        else d = Math.abs(Math.pow(x2-x1,2)) + Math.abs(Math.pow(y2-y1,2));
        //Закончили находить d - расстояние между центрами окружностей
        if(d > R1+R2){
            return 3;
        }
        else if(d == R1+R2){
            return 4;
        }
        else if(d==Math.abs(R1-R2)){
            System.out.println("\nОкружности имеют 1 общую точки");
            if(R1<R2){
                return 1;
            }
            else return 2;
        }
        else if(d<Math.abs(R1-R2)){
            System.out.println("\nОкружности не имеют общие точки");
            if(R1<R2){
                return 1;
            }
            else return 2;
        }
        //return this.x1; //chek не имеет доступа к этой переменной и даёт ошибку
        else if(Math.abs(R1-R2)<d&&d<Math.abs(R1+R2)){
            System.out.println("\nОкружности имеют 2 общие точки");
            if(R2>R1){
                return 1;
            }
            else if(R2<R1){
                return 2;
            }
            else if(R2==R1){
                return 8;
            }
            else return 0;
        }
        else return 0;
    }
}