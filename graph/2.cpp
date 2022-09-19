#include <iostream>
#include <vector>
using namespace std;
int main (){
    int n, m , x, y;
    cin >> n >> m;
    vector <int> g[100];
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++){
        cout << i << " - ";
        for (int j = 0; j < g[i].size(); j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
6 9
0 4
0 5
1 2
1 3
1 5
2 3   
2 4
2 5
4 5
*/

//1:56 остановилась 