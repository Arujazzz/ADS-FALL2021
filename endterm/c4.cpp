#include <iostream>
#include <vector>
using namespace std;
int pr[200100];
int ans[200100];
vector<int> g[200100];
int used[200100];

bool dfs(int v, int i) {
    int result = 0;
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(to != i) {
            if(used[to] == 1) {
                result = 1;
            } else if (used[to] == 0){
                result |= dfs(to, i);
            }
        }
    }
    used[v] = 2;
    return result;
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            used[j] = 0;
        }
        int result = 1;
        for(int j = 1; j <= n; j++) {
            if (i != j) {
                result &= (!dfs(j, i));
            }
        }
        ans |= result;
    }
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}