public class Mass {
    int [][] mass = null;
    int N=(int)(Math.random()*10*0.7+1);
    int M=(int)(Math.random()*10*0.7+1);
    public Mass(){
        mass = new int [N][M];
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++) {
                mass[i][j] = (int) (Math.random() * ((100 - 20 + 1)) - 50);
            }
    }
    public void Show() {
        for (int i = 0; i < N; i++) {
            System.out.println("");
            for (int j = 0; j < M; j++) {
                System.out.print(mass[i][j]);
                System.out.print(" ");
            }
        }
    }
}
