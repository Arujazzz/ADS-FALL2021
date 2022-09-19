#include <bits/stdc++.h>
using namespace std;

int n;
string s;
queue<int> kat;
queue<int> sak;

int main() {
    cin >> n;
    cin >> s;
    for(int i = 0; i < n;i++){
        if (s[i] == 'K') kat.push(i);
        else sak.push(i);
    }
    while(true) {
        if(kat.empty()) {
            cout << "SAKAYANAGI";
            return 0;
        }
        if(sak.empty()) {
            cout << "KATSURAGI";
            return 0;
        }
        int kt = kat.front();
        int sk = sak.front();
        sak.pop();
        kat.pop();
        if(kt < sk) kat.push(n + kt);    
        else sak.push(n + sk);
        
    }
}