//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        final var scanner = new Scanner(System.in);
        System.out.println("1я матрица:");
        final var matrixA = inputMatrix(scanner);
        System.out.println("2я матрица:");
        final var matrixB = inputMatrix(scanner);
        final var matrixM = multiply(matrixA, matrixB);
        if (matrixM == null) {
            return;
        }
        System.out.println("Матрица-результат:");
        final var len = max_len(matrixM);
        final var format = "%" + len + "." + len + "s ";
        for (var i = 0; i &lt; matrixM.length; i++) {
            for (var j = 0; j &lt; matrixM[0].length; j++) {
                System.out.printf(format, matrixM[i][j]);
            }
            System.out.println();
        }
    }

    private static int max_len(final int[][] m) {
        var max = m[0][0];
        for (var i = 0; i < m.length; i++) {
            for (var j = 0; j < m[0].length; j++) {
                if (m[i][j] < &gt; max) {
                    max = m[i][j];
                }
            }
        }
        return Double.valueOf(Math.log10(max)).intValue() + 1;
    }
}