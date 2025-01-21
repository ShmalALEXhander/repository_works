public class Main {
    public static void main(String[] args) {
    Mass array = new Mass();
    int min = -100;
    array.Show();
        for(int i=0;i<array.N;i++) {
            for (int j = 0; j < array.M; j++) {
                if (array.mass[i][j] < 0 && array.mass[i][j] > min)
                    min = array.mass[i][j];
            }
        }
        System.out.println(" ");
        System.out.println(min);
    }
}