#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main (){
    vector <string> s;
    string x;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        s.push_back(x);
    }

    int p = 31;
    vector <long long> p_pow(10000);
    p_pow[0] = 1;
    for (int i = 1; i < 10000; i++){
        p_pow[i] = p_pow[i - 1] * p;
    }

    vector <long long> hashes(n);
    for (int i = 0; i < n; i++){
        long long hash = 0;
        for (int j = 0; j < s[i].size(); j++){
            hash += (s[i][j] - 'a' + 1) * p_pow[i];
            
        }
        hashes.push_back(hash);
        hash = 0;
    
    }
    for (int i = 0; i < n; i++){
        cout << hashes[i] <<endl;
    }


/*
    int g = 0;
    //sort(hashes.begin(), hashes.end());
    for (int i = 0; i < n; i++){
        if (hashes[i] != hashes[i - 1]){
            cout << "OK" << endl;
        }else cout << hashes[i] << ++g << endl;    
    }  
  */  
    return 0;
}