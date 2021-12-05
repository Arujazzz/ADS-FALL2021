#include <iostream>
#include <vector>
using namespace std;
int main (){
    string s, t;
    cin >> s >> t;
    int p = 31;
    vector <long long> p_pow(max(s.size(), t.size()));

    p_pow[0] = 1;
    for (int i = 1; i<p_pow.size(); i++){
        p_pow[i] = p_pow[i-1] * p;
    }

    long long h_s = 0;
    for(int i = 0; i < s.size(); i++){
        h_s += (s[i] - 'a' + 1) * p_pow[i];
    }

    vector <long long> h(t.size());
    for (int i = 0; i < t.size(); i++){
        h[i] = (t[i] - 'a' + 1) * p_pow[i];
        if (i){
            h[i] += h[i - 1];
        }
    }

    for (int i = 0; i + s.size() - 1 < t.size(); i++){
        long long cur_h = h[i + s.size() - 1];
        if (i){
            cur_h -= h[i - 1];
        }
        if (cur_h == h_s * p_pow[i]){
            cout << i << " ";
        }
    }


    return 0;
}