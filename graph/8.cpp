#include <iostream>
using namespace std;
int g[100][100];
int c[100][100];

int main (){
    int n, m, x, y, l;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            g[i][j] = 1e7;
        }
        g[i][i] = 0;
    }
    for (int i = 0; i < m; i++){
        cin >> x >> y >> l;
        g[x][y] = l;
        g[y][x] = l;
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (g[i][j] > g[i][k] + g[k][j] ){
                    g[i][j] = g[i][k] + g[k][j];
                    c[i][j] = k;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
6 9
0 4 2
0 3 6
3 4 1
4 1 4
3 1 2 
3 5 5
1 5 3
1 2 1
5 2 2

0 5 6 3 2 8 
5 0 1 2 3 3
6 1 0 3 4 2
3 2 3 0 1 5
2 3 4 1 0 6
8 3 2 5 6 0
*/ 