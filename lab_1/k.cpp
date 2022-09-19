#include <bits/stdc++.h>
using namespace std;
int main(){
    long long b;
    bool c = true;
    cin >> b;
    if(b == 0 || b == 1){
        c = false;
    }else{
        for(int i = 2; i <= sqrt(b); i++){
            if(b%i == 0){
                c = false;
                break;
            }
        }
    }
    if(c) cout <<"prime";
    else cout <<"composite";

    return 0;
}