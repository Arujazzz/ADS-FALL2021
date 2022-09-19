#include <iostream>
#include <vector>
using namespace std;
int d[1000000];
int res[1000000];
vector<int> g[100000];
int used[1000000], n, m, x, y;

// поиск в глубину для каждой вершины
bool dfs(int v) {
    used[v] = 1; // посещаем вершину 
    int result = 0;

    for(size_t i = 0; i < g[v].size(); i++) {
        int x = g[v][i]; // следующая вершина графа
        if(used[x] == 1)// если мы ее посетили, но не вышли из нее, значит мы нашли цикл
            result = 1;// ставим индикатор, что мы нашли цикл и останавливаемся
        else if (used[x] == 0)// если не посетили, то посещаем 
            result = result | dfs(x);
    used[v] = 2; // если не нашли цикл, то выходим из вершины 
    }
    return result;

}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            used[j] = 0;
        }
        int result = 1;
        for(int j = 1; j <= n; j++) {
            if (i != j) {
                result &= (!dfs(j));
            }
        }
        ans = ans | result;
    }
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}