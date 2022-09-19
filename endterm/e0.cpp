#include <iostream>
#include <vector>
using namespace std;
int d[200100];
int ans[200100], n, m, x, y, cnt = 0;
vector<int> g[200100];

int get_parent(int v) {
    while(d[v] != d[d[v]] && d[v] != 0)
        d[v] = d[d[v]];
    return d[v];
}
int main() {
    cin >> n >> m;
    vector<pair<int, int> > v;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        v.push_back(make_pair(x, y));
    }

    for (int i = 0; i < n; i++){
        cout << i << " -- ";
        for (int j = 0; j <= g[i].size(); j++){
            cout << g[i][j]<<" ";
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "////////////"<< endl;
    
    for(int i = n; i >= 1; i--) {
        ans[i] = cnt;
        int s = get_parent(i);
        if (s == 0) {
            cnt += 1;
            d[i] = i;
        }
        cout << "i: " << i << endl;
        cout << "s: " << s << " and " << "cnt: " << cnt;
        cout << endl;

        for(int j = 0; j < g[i].size(); j++) {
            int b = g[i][j];
            cout << "b -- i: " << b << " -- " << i<< endl;
            if (b > i) {
                int s = get_parent(i);
                int f = get_parent(b);
                if(s != f) {
                    d[f] = s;
                    cnt -= 1;
                }
            }
        }
    }

/*
4 5
1 4
5 4
2 4
1 3
1 2
4 2
2 1
4 1
3 1
*/

    cout << endl;
    cout << "*********"<< endl;
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}