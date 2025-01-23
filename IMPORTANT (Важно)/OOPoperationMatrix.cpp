#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    vector <vector<int>> matrix;
    int R, C;

public:
    Matrix(int r, int c)  {
        R = r;
        C = c;
        matrix.resize(R, vector <int>(C,0));
    }
    Matrix(int r, int c, vector <vector<int>> arr) {
        R = r;
        C = c;
        matrix.resize(R, vector <int>(C, 0));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                matrix[i][j] = arr[i][j];
        }
    }
    
  /*  int getValue(int r, int c) {
        return matrix[r][c];
    }
    void setValue(int r, int c, int value) {
        matrix[r][c] = value;
    }*/

    void Transposition() {// length и
        for (int i = 0; i < R; i++) {
            for (int j = i + 1; j < C; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
    //Необходим геттер и сеттер
    Matrix operator+ (Matrix B) {
       // Matrix B = Matrix(R, C);
        Matrix Res(R, C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                Res.matrix[i][j] = matrix[i][j] + B.matrix[i][j];
                //Res.setValue(i, j, this->getValue(i, j) + B.getValue(i, j));
            }
        }
            return Res;
    }
    int operator== (Matrix B) {
        int tmp = 0;
        Matrix Res(R, C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {  
                if (matrix[i][j] == B.matrix[i][j])
                    tmp++;
                /*Res.setValue(i, j, this->getValue(i, j) == B.getValue(i, j));
                if (this->getValue(i, j) == B.getValue(i, j)) {
                    tmp++;
                }*/
            }
        }
        return (tmp == (R * C));
        /*if (tmp == (R * C))
            return 1;
        else return 0;*/
    }
    Matrix operator* (Matrix B) {
        Matrix Res(R, C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {  
                //Res.matrix[i][j] = 0;
                for (int k = 0; k < C; k++) {
                    Res.matrix[i][j] += matrix[i][k] * B.matrix[k][j];
                    //Res.setValue(i, j, this->getValue(i, k) * B.getValue(k, j));
                }
            }
        }
        return Res;
    }
    Matrix operator* (int Num) {
        Matrix Res(R, C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                Res.matrix[i][j] = matrix[i][j] * Num;
                /*Res.setValue(i, j, this->getValue(i, j) * Num);*/
            }
        }
        return Res;
    }
    void print() {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix A = Matrix(3, 3,
        { {1,2,7},
         {3,4,6},
         {5,8,3}
        });


    Matrix B=Matrix(3, 3,
        { {5,6,3},
         {7,8,1},
         {4,1,2}
        });

    Matrix G = Matrix(2, 2, { {3,5}, {7,1} });

    Matrix C = A + B;
    cout << " ////////////////";
    Matrix L = (A + (B * A) + B) *5;
    cout << "L = A + B\n ";
    L.print();
    
   
    cout << "Matrix A:" << endl;
    A.print();

    cout << "Matrix B:" << endl;
    B.print();

    cout << "Matrix G:" << endl;
    G.print();

    cout << "Matrix C (A + B + G):" << endl;
    C.print();
    cout << "Comparison = "; int t = (A == A);
    cout << t;
    cout << "\n";
    cout << "Comparison = "; int v = (A == B);
    cout << v;
    cout << "\n";
    C.print();
    C.Transposition();
    cout << "\n";
    C.print();


    Matrix D = A * B;
    cout << "Matrix D (A * B):" << endl;
    D.print();
    cout << endl;
    Matrix F = A * 5;
    cout << "Matrix F (A * 5):" << endl;
    F.print();
}