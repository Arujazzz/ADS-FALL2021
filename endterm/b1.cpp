#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph; 
vector<int> used;
vector <int>d;


int flag, n, m, x , y;

void dfs (int v) {
    if (flag == 1) 
        return;
    else {
        used[v] = 1; 
        d.push_back(v); 
        for (int i = 0; i < graph[v].size(); i++) {
            int to = graph[v][i];
            if (used[to] == 1) { 
                d.push_back(to); 
                flag = 1; 
                return;
            } 
            else {
                dfs(to); 
            }
            if (flag == 1) 
                return; 
        }
        used[v] = 2; 
        d.pop_back();
    }
} 

void checkNodes() { 
    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) { 
            dfs(i);
            if (flag == 1) return; 
        }
    }
} 

int main(){
    cin >> n >> m; 
    graph.resize(n + 1); 
    used.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        cin >> x >> y; 
        graph[x].push_back(y);
    }
    checkNodes();  
    if (flag == 1) { 
        int i = d.size() - 2; 
        int to = d.back(); 
        while (d[i] != to) { 
            i--;
        }
        cout << "Possible" << endl;
        while (i < d.size() - 1) {
            cout << d[i] << " ";
            i++; 
        }
        cout << endl;
    }
    else cout << "Impossible" << endl;
}