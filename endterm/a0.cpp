#include <bits/stdc++.h>

using namespace std;


vector <pair<int,int>> g[100500];

int n, m, x, y, l;

long long dist[100000];

long long fun_l(int a, int b) {
	for (int i = 1; i <= n; i++) dist[i] = 1e18;
	set <pair<long long, int>> s;
	dist[a] = 0; //теперь при добавлении каждой вершины  мы вычисляем расстояние до неё
	s.insert({0, a});
	while (!s.empty()) {
		int v = s.begin() -> second;
		cout <<"{"<< s.begin() ->first<< ","<< s.begin()->second<<"}";
		s.erase(s.begin());

		
		for (auto to : g[v]) {
			if (dist[to.first] > dist[v] + to.second) {
				s.erase({dist[to.first], to.first});
				dist[to.first] = dist[v] + to.second;
				s.insert({dist[to.first], to.first});

			}
		}
	}
	return dist[b]; 
}
int main() {

	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf ("%d %d %d", &x, &y, &l);
		g[x].push_back({y, l});
		g[y].push_back({x, l});
	}
	int a, b, c, d;
	scanf ("%d %d %d %d", &a, &b, &c, &d);
	long long res = min(fun_l(a, b) + fun_l(b, c) + fun_l(c, d), fun_l(a, c) + fun_l(c, b) + fun_l(b, d));
	if (res >= 1e18) res = -1;
	cout << res;
	cout << fun_l(a, b)<< endl;
	cout <<fun_l(b, c) << endl;
	cout <<fun_l(c, d);

	return 0;
}