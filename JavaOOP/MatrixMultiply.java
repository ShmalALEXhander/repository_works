import static java.lang.Math.min;

public class MatrixMultiply {

    static    int dp[][]  ;      // dp[i][j] — ответ на отрезке [i, j)
    static    int v[] = {2,3,4,5, 6, 7} ;        // Массив v[] — хранит все размеры матриц по порядку
    // Так как у нас размеры соседних матриц по вертикали и горизонтали совпадают, то они занесены в этот массив однократно
    public static void main(String[] args) {
        dp = new int[v.length][v.length];
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                dp[i][j] = -1;
            }
        }
        System.out.println(matrixChainMultiplication(0, v.length-1));
    }

    // l — включая в отрезок, r — исключая из отрезка. Изначально l = 0, r = n, где n — длина последовательности

    public static     int matrixChainMultiplication(int l, int r){
        if (dp[l][r] == -1) {                   // Если значение динамики не посчитано
            if (l == r - 1){
                dp[l][r] = 0;                   // Если у нас подотрезок длины 1, то количество операций для перемножения равно нулю
            }
            else{
                dp[l][r] = Integer.MAX_VALUE;

                for (int i = l + 1; i < r; i++){
                    dp[l][r] = min(dp[l][r], v[l] * v[i] * v[r] +  matrixChainMultiplication(l, i) + matrixChainMultiplication(i, r));
                }

            }

        }
        return dp[l][r];
    }
}
