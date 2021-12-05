#include <iostream>
#include <vector>
const int MAX_INT = 1e7;

using namespace std;
vector<int> d(100, MAX_INT);
int n, m, x, y, l;
int g[100][100];
int used[100];
int c[100];
int res = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> l;
        g[x][y] = l;
        g[y][x] = l;
    }
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || d[v] > d[j]))
                v = j;
        }
        used[v] = true;
        cout << v << endl;
        for (int i = 0; i < n; i++) {
            if (!used[i] && g[v][i] && d[i] > g[v][i]) {
                d[i] = g[v][i];
                c[i] = v;
            }
        }
    }
    for (int i = 0; i < n; i++){
        res += d[i];
        cout << i << " " << c[i] << " "<< d[i] << endl;
    }

    cout << res;
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
5 2 2     0+2+1+1+2+2=8
*/