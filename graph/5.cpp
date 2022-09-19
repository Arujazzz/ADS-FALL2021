#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, l, v;
int color[100];
vector <int> g[100];
bool ok;

void dfs(int v, int c){
    color[v] = c;
    for (int i = 0; i <g[v].size(); i++){
        int y = g[v][i];
        if (color[y] == 0){
            dfs(y, 3-c);
        }else {
            if (color[y] == c){
                ok = false;
            }
        }
    }
}

int main (){
    ok = true;
    int cnt = 0;
    cin >>n >> m;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }    
    for (int i = 0; i < n; i++){
        if (color[i] == 0)
            dfs(i, 1);
    }
    if (ok)
        cout << "YES";
    else 
        cout << "NO";

    return 0;
}
/*
7 7
0 2
2 4
2 3
3 1
1 6
1 4
4 5
YES

7 8
0 2
2 4
2 3
3 1
1 6
1 4
4 5
5 2
NO
*/