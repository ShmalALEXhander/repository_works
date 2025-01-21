import java.util.Scanner;
public class Matrixes {
 static  int[][] InputMatrix(final Scanner scanner) {
     System.out.println("Введите кол-во строк матрицы:");
     int rows = scanner.nextInt();
     System.out.println("Введите кол-во столбцов матрицы:");
     int cols = scanner.nextInt();
     System.out.println("Введите матрицу:");
     int[][] matrixA = new int[rows][cols];
     for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++)
             matrixA[i][j] = scanner.nextInt();

     }
     return matrixA;
 }
  static int[][] Addition(int[][] matrixA, int[][] matrixB) {
      int cols = matrixA[0].length; // Раз length константа, то от такой оптимизации код не станет быстрей, просто более читабелен.
      int rows = matrixA.length;
      int[][] matrixF = new int[rows][cols]; // Константа
      for (var i = 0; i < rows; i++)
          for (var j = 0; j < cols; j++) {
              matrixF[i][j] += matrixA[i][j] + matrixB[i][j];
          }
      return matrixF;
  }
  static int[][] Transposition(int[][] matrix) {// length и
      int cols = matrix[0].length;
      int rows = matrix.length;
      for (int i = 0; i < rows; i++) {
          for (int j = i + 1; j < cols; j++) {
              int tmp = matrix[i][j];
              matrix[i][j] = matrix[j][i];
              matrix[j][i] = tmp;
          }
      }
      return matrix;
  }

   static int[][] multiplyNumber(int[][] matrix, int Number) {
       int[][] matrixF = new int[matrix.length][matrix.length];
       for(var i = 0;i < matrix.length; i++) {
           for (var j = 0; i < matrix.length; i++)
               matrixF[i][j] += matrix[i][j] * Number;
       }
       return matrixF;
   }

   static int[][] multiply(int[][] matrixA, int[][] matrixB) {
       if (matrixA[0].length != matrixB.length) {
           System.err.println("Эти матрицы нельзя перемножить");
           return null;
       }
        int[][] matrixF = new int[matrixA.length][matrixB[0].length]; //va
        for (var i = 0; i < matrixF.length; i++) {
            for (var j = 0; j < matrixF[0].length; j++) {
                matrixF[i][j] = 0;
                for (var k = 0; k < matrixA[0].length; k++) {
                    matrixF[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
        return matrixF;
    }
    static int max_len(final int[][] m){
        var max = m[0][0];
        for (var i = 0; i < m.length; i++) {
            for (var j = 0; j < m[0].length; j++) {
                if (m[i][j] > max) {
                    max = m[i][j];
                }
            }
        }
        return Double.valueOf(Math.log10(max)).intValue() + 1;
    }
    static void PrintF(int [][] m){
        int len = max_len(m);
        final var format = "%" + len + "." + len + "s ";
        System.out.println();
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[0].length; j++) {
                System.out.printf(format, m[i][j]);
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        final var scanner = new Scanner(System.in);
        System.out.println("1ая матрица:");
        int[][] matrixA = InputMatrix(scanner);
        System.out.println("2ая матрица:");
        int[][] matrixB = InputMatrix(scanner);
        int[][] matrixF = multiply(matrixA, matrixB);
       // Addition(matrixA,matrixB);
        if (matrixF == null) {
            return;
        }
        System.out.println("Матрица-результат:");
        PrintF(matrixF);
        int [][] TranspMatrix = Transposition(matrixF);
        PrintF(TranspMatrix);
        int [][] TranspMatrix1 = Transposition(TranspMatrix);
        PrintF(TranspMatrix1);
        TranspMatrix1 = multiplyNumber(TranspMatrix1, 5);
        PrintF(TranspMatrix1);
    }
}
