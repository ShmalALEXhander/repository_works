#include <iostream>
#include <cstring>
using namespace std;
#define INF 9999999

int main() {
    const int V = 5;
    int G[V][V] = {
        {0,7,2,5,0},
        {7,0,3,0,5},
        {2,3,0,4,6},
        {5,0,4,0,3},
        {0,5,6,3,0} //неполный граф. посмотри подробно.
    };
    int no_edge;
    int selected[V];
    memset(selected, false, sizeof(selected));
    no_edge = 0;

    selected[0] = true; //Подозреваю что массив посещений.

    int x;            //  row number
    int y;            //  col number

    cout << "Edge" << " : " << "Weight";
    cout << endl;
    while (no_edge < V - 1) { //???? Почему Такое условие у цикла, оно странно т.к. оперируют между собой и рёбрами и вершинами
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) { //Были ли мы именно в этой строке.
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }

                }
            }
        }
    cout << x+1 << " - " << y+1 << " :  " << G[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
    }
    return 0;

}
