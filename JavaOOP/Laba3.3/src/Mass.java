public class Mass {
    int[][] mass = null;
    public Mass(){
        mass = new int [3][3];
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                mass[i][j]=(int)(Math.random()*((100-20+1)) -50);
            }
    }
    public void Show() {
        for(int i=0;i<3;i++){
            System.out.println("");
            for(int j=0;j<3;j++){
                System.out.print(mass[i][j]);
                System.out.print(" ");
            }
        }
    }
}
