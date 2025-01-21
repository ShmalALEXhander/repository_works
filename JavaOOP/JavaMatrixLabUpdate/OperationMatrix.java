import java.util.Scanner;

public class OperationMatrix {
//Хочу написать ввод
    static int[][] InputMatrix(final Scanner scanner) {
        final var rows = scanner.nextInt();
        final var cols = scanner.nextInt();
        final var matrixA = new int[rows][cols];
        for (var i = 0; i < rows; i++)
            for (var j = 0; j < cols; j++) {
                matrixA[i][j] = scanner.nextInt();
            }
        return matrixA;
    }
    public int[][] multiply(int[][] matrixA, int[][] matrixB) {
        if (matrixA[0].length != matrixB.length) {
            return null;
        }
        int[][] matrixM = new int[matrixA.length][matrixB[0].length];
        for (int i = 0; i < matrixM.length; i++) {
            for (int j = 0; j < matrixM[0].length; j++) {
                matrixM[i][j] = 0;
                for (var k = 0; k < matrixA[0].length; k++) {
                    matrixM[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
        return matrixM;
    }
}
