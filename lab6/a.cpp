#include <iostream>
#include <vector>
using namespace std;
int main (){
    string s, t;
    cin >> s;
    cin >> t;

    int p = 31;
    vector <long long> p_pow(s.size());
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); i++){
        p_pow[i] = p_pow[i - 1] * p;
    }

    long long h_t = 0;
    for (int i = 0; i < t.size(); i++){
        h_t += (t[i] - 'a' + 1) * p_pow[i];
    }

    vector <long long> h(s.size());
    for (int i = 0; i < s.size(); i++){
        h[i] = (s[i] - 'a' + 1) * p_pow[i];
        if (i) h[i] += h[i - 1];
    }

    for (int i = 0; i + t.size() - 1 < s.size(); i++){
        long long curr_h = h[i + t.size() - 1];
        if (i) curr_h -= h[i - 1];
        if (curr_h == h_t * p_pow[i]) cout << i << " "; 
    }

 
    return 0;
}