#include <bits/stdc++.h>
using namespace std;

int used[100000], par[100000], n, k, x, y;
vector<int> g[100000];
vector <int> a, b, c;
int cnt[100000];

void print(int vis){
        cout << vis << " ";
        used[vis] = 1;
        for(int i : g[vis])
                if(used[i] == 0)
                        print(i);
}

void dfs(int vis, int p){
        used[vis] = 1;
        par[vis] = p;
        cnt[p]++;
        for(int i : g[vis]){
                if(used[i] == 0){
                        dfs(i, p);
                }
        }
}

int main(){
        cin >> n >> k;
        for(int i = 0; i < k; i ++){
                cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }

        for(int i = 1; i <= n; i ++){
                if(used[i] == 0){
                        par[i] = i;
                        dfs(i, i);
                        if(cnt[i] > 3){
                                cout << -1;
                                return 0;
                        }
                        if(cnt[i] == 1) a.push_back(i);
                        if(cnt[i] == 2) b.push_back(i);
                        if(cnt[i] == 3) c.push_back(i);
                }
        }
        for(int i : b){
                if(a.size() == 0){
                        cout << -1;
                        return 0;
                }
                int t = a.back();
                a.pop_back();
                g[i].push_back(t);
                g[t].push_back(i);
        }
        if(a.size() % 3 != 0){
                cout << -1;
                return 0;
        }
        
        for(int i = 1; i <= n; i ++){
                used[i] = 0;
        }
        for(int i : b){
                print(i);
                cout << endl;
        }
        for(int i : c){
                print(i);
                cout << endl;
        }
        for(int i = 0; i < a.size(); i++){
                cout << a[i] << " ";
                int j = (i + 1) % 3;
                if(j == 0)
                        cout << endl;
        }
        return 0;
}