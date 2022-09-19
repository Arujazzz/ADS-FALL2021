#include <iostream>
#include <vector>
using namespace std;

vector <int> p_f(string s){
    int n = s.size();
    vector <int> p(n);
    for (int i = 1; i < n; i++){
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j = j + 1;
        p[i] = j;
    }
    return p;
}

int main (){
    int n;
    string s;
    string t;
    cin >> n;
    cin >> s;
    cin >> t;

    int res = 0;
    string q = s + '#' + t + t;
    vector <int> p = p_f(q);
    for (int i = 0; i < q.size(); i++){
        if (p[i] == s.size())
            res = i - 2*s.size();
    }
    if (res) cout << res;
    else cout << -1;
}