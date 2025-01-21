public class Main {
    public static void main(String[] args) {
        Mass array = new Mass();
        array.Show();
        System.out.println("");
        for(int i=0;i<3;i++) {
            boolean flag = true;
            while (flag) {
                flag = false;
                for (int j = 0; j < 3 - 1; j++)
                    if (array.mass[i][j] > array.mass[i][j + 1]) {
                        int tmp = array.mass[i][j];
                        array.mass[i][j] = array.mass[i][j + 1];
                        array.mass[i][j + 1] = tmp;
                        flag = true;
                    }
            }
        }
        array.Show();
    }
}
