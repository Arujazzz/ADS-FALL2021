#include <iostream>
#include <vector>
using namespace std;
int g[10000][10000];
int c[10000][10000];


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
        x--;
        y--;
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
    int d1, d2, d3, d4;
    cin >> d1>>d2>>d3>>d4;
    int s1 = 0, s2 = 0, s3 = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            s1 = g[d1][d2];
            s2 = g[d2][d3];
            s3 = g[d3][d4];
        }
    }
   
    if (s1 == 10000000 || s2 == 10000000 || s3 == 10000000){
        cout << -1;
    }
    cout << s1+s2+s3;
    
    return 0;
}