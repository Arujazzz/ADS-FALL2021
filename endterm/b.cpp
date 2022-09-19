#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> g[200100];
int used[200100];
bool dfs(int v) {
    int result = 0;
    used[v] = 1;
    for(size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(used[to] == 1) {
            result = 1;
        } else if (used[to] == 0){
            result |= dfs(to);
        }
    }
    used[v] = 2;
    return result;
}
vector<int> ansv;
void dfs2(int v) {
    used[v] = 1;
    for(size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(!used[to]) dfs2(to);
    }
    ansv.push_back(v);
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if (!used[i]) {
            ans &= (!dfs(i));
        }
    }
    if (!ans) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for(int i = 1; i <= n; i++) {
        used[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            dfs2(i);
        }
    }
    reverse(ansv.begin(), ansv.end());
    for(size_t i = 0; i < ansv.size(); i++) {
        cout << ansv[i] << ' ';
    }
    cout << endl;
    return 0;
}