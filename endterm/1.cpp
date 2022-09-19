#include <iostream>
using namespace std;
int g[100][100];
int c[100][100];

int main (){
    int n, m, x, y, l;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            g[i][j] = 1e7;
        }
        g[i][i] = 1;
    }
    for (int i = 1; i <= m; i++){
        cin >> x >> y >> l;
        g[x][y] = l;
        g[y][x] = l;
        
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (g[i][j] > g[i][k] + g[k][j] ){
                    g[i][j] = g[i][k] + g[k][j];
                    c[i][j] = k;
                }
            }
        }
    }
    int s1 = 0, s2 = 0, s3 = 0;
    int res = 0;

    int d1, d2, d3, d4;
    cin >> d1 >> d2 >> d3 >> d4;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << g[i][j] << " ";
            s1 = g[d1][d2];
            s2 = g[d2][d3];
            s3 = g[d3][d4];
        }
        cout << endl;
    }
    cout << endl;
    cout << s1 + s2 + s3<< endl;
    cout << s1<<s2<<s3;

    //res = s1 + s2 + s3;
    //cout << res;
    return 0;
}