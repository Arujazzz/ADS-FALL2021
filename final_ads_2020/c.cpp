#include <iostream>
using namespace std;

int n, m, x, y, ok[1000][1000];



int main(){
    cin >>n>>m;
    for (int i = 1; i <= m; i++){
        cin >> x>>y;
        ok[x][y] = 1;
        ok[y][x] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (ok[i][j] == 0 && j == i + 1)
                cnt += 1;
        }
    }

    cout << n- 1-m;

    return 0;
}