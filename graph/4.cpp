//обход в глубину
#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, v;
int used[100];
vector <int> g[100];

void dfs(int v){
    cout << v << " ";
    used[v] = 1;
    for (int i = 0; i< g[v].size(); i++){
        int y = g[v][i];
        if (used[y] == 0){
            dfs(y);
        }
    }
}

int main (){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    /*
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (used[i] == 0){
            cnt += 1;
            dfs(i);
        }
    }
    cout << cnt;
    */
    cin >> v;
    dfs(v);
    return 0;
}

/*
6 7
0 1
0 5
1 2
2 4
2 3
3 4
4 5
2
*/