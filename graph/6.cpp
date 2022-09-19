#include <iostream>
#include <vector>
#define MAX_INT 1e7
using namespace std;

int n, m, x, y, l;
int g[100][100];
int used[100];
int c[100];
vector <int> d(100, MAX_INT);

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> l;
        g[x][y] = l;
        g[y][x] = l;
    }
    int k;
    cin >> k;
    d[k] = 0;
    for (int i = 0; i < n; i++){
        int v = -1;
        for (int j = 0; j < n; j++){
            if (!used[j] && (v == -1 || d[v] > d[j])){
                v = j;
            }
        }

        cout << v << " ";
        cout << endl;

        used[v] = true;
        //v -> j
        for (int j = 0; j < n; j++){
            if (!used[j] && g[v][j] > 0){
                if (d[j] > d[v] + g[v][j]){
                    d[j] = d[v] + g[v][j];
                    c[j] = v;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << d[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++){
        cout << c[i] << " ";
    }

    return 0;
}
/*
6 9
0 2 1
0 4 6
2 4 4
2 1 1
1 4 1
1 3 5
4 3 2
1 5 10
3 5 1
*/