#include <bits/stdc++.h>

using namespace std;


vector <pair<int,int>> g[100500], g1[100500];

int n, m;
long long dist[100500];
bool ok[511][511];

long long cost(int a, int b, vector <pair<int,int>> gr[]) {
	for (int i = 1; i <= n; i++) dist[i] = 1e18;
	set <pair<long long, int>> s;
	dist[a] = 0; //теперь при добавлении каждой вершины в cет мы вычисляем расстояние до неё
	s.insert({0, a});
	while (!s.empty()) {
		int v = s.begin() -> second;
        cout << "{"<< s.begin() -> first << "," << s.begin() ->second <<"}";
		s.erase(s.begin());
        
		
		for (auto to : gr[v]) {
			if (dist[to.first] > dist[v] + to.second) {
				s.erase({dist[to.first], to.first});
				dist[to.first] = dist[v] + to.second;
				s.insert({dist[to.first], to.first});

                // Добавляем найденный минимальный вес
    // к текущему весу вершины
    // и сравниваем с текущим минимальным весом вершины
			}
		}
	}
	return dist[b];
}
int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d %d", &a, &b);
		g[a].push_back({b, 1});
		g[b].push_back({a, 1});
		ok[a][b] = 1;
		ok[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && !ok[i][j]) {
				g1[i].push_back({j, 1});
			}
		}
	}
    cout << "*******"<< endl;
    
	long long ans = max(cost(1, n, g), cost(1, n, g1));
	if (ans >= 1e18) ans = -1;

    cout << cost(1, n, g)<< endl;
    cout << cost(1, n, g1)<< endl;


	cout << ans;
	return 0; 
}