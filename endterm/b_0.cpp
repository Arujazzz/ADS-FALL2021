#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g[1000000];
vector<int> res;
int used[1000000], n, m, x, y;


// поиск в глубину для каждой вершины
bool dfs(int v) {
    used[v] = 1;  // посещаем вершину 
    int result = 0;

    for(size_t i = 0; i < g[v].size(); i++) {
        int x = g[v][i]; // следующая вершина графа
        if(used[x] == 1) { // если мы ее посетили, но не вышли из нее, значит мы нашли цикл
            result = 1; // ставим индикатор, что мы нашли цикл и останавливаемся
        } else if (used[x] == 0){ // если не посетили, то посещаем 
            result = result | dfs(x);
        }
    }
    used[v] = 2; // если не нашли цикл, то выходим из вершины 
    return result;
}

// проверяем вершины на наличие цикла 
void dfs_1(int v) {
    used[v] = 1; // посещаем вершину 
    for(size_t i = 0; i < g[v].size(); i++) {
        int x = g[v][i]; // следующая вершина графа
        if(!used[x]) // если не посещали вершину, то посещаем ее 
            dfs_1(x);
    }
    res.push_back(v); // добавляем ее в порядок обхода графа
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }

    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if (!used[i])
            ans = ans & (!dfs(i));
    }
    if (!ans){
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    for(int i = 1; i <= n; i++) {
        used[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i]) 
            dfs_1(i);
    }
    reverse(res.begin(), res.end());
    for(size_t i = 0; i < res.size(); i++) 
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}