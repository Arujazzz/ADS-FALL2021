#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector <pair<int,int>> g[1000000];
int n, m, x, y, l, d1, d2, d3, d4;
long long dist[1000000];

long long func_l(int a, int b) {
	for (int i = 1; i <= n; i++) 
		dist[i] = 1e18;
	
	set <pair<long long, int>> s;
	dist[a] = 0;
	s.insert({0, a});
	while (!s.empty()) {
		int v = s.begin() -> second;
		s.erase(s.begin());
		
		for (auto to : g[v]) {
			if (dist[to.first] > dist[v] + to.second) 
				s.erase({dist[to.first], to.first});
				dist[to.first] = dist[v] + to.second;
				s.insert({dist[to.first], to.first});
		}
	}
	return dist[b];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> l;
		g[x].push_back({y, l});
		g[y].push_back({x, l});
	}
	cin >> d1>>d2>>d3>>d4;
	long long ans = min(func_l(d1, d2) + func_l(d2, d3) + func_l(d3, d4), func_l(d1, d3) + func_l(d3, d2) + func_l(d2, d4));
	if (ans >= 1e18) ans = -1;
	
	cout << ans;
	return 0;
}