#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n;
string s, t;
set <string> st;
int p = 31;

void get_hash(string s, string t){
    int cnt = 0;
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
        if (curr_h == h_t * p_pow[i]) 
            cnt += 1; 
    }
    cout << cnt;
}
int cnt = 0;
int main (){
    cin >> n;
    while (n != 0){
        cin >> t;
        if (t == "+"){
            cin >> s;
            st.insert(s);
        }
        if (t == "-"){
            cin >> s;
           st.erase(s);
        }
        if (t == "?"){
            cin >> s;
            for(set<string>::const_iterator it = st.begin(); it != st.end(); it++){
                for (int i = 0; i < (*it).size(); i++){
                    if (s == (*it).substr(0, i))
                    cnt += 1;
                }
            }
            cout << cnt;
        }
        n--;   
    }
    return 0;
}