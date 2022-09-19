#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

int n, x, y, dist[100000];
vector <pair<int, int>> g[100000000];
vector <int> res; 

int get_abs(int a){
    if (a < 0) a = a * (-1);
    return a;
}


int main (){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x >> y;
        g[i].push_back({x, y});
    }
    vector <int> ans;
    int max = 0;
    for (int i = 1 ; i <= n; i++){
        for (vector <int> it :: it = g[i].begin(); it != g[i].end();){
            int ans1 = g[i + 1].begin() -> first - g[i].begin() -> first;
            int ans2 = g[i + 1].begin() -> second - g[i].begin() -> second;
            int ans3 = get_abs(ans1) + get_abs(ans2);
            cout << i <<" "<< ans3<< endl;
        }
    }
    //cout << max;
    

    return 0;
}