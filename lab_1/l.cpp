#include <bits/stdc++.h>
using namespace std;

int gcd(long long a, long long  b){
    while (a > 0 && b> 0){
        if (a > b)
            a%=b;            
         else
            b%=a;
    }
    if (a == 0)
        return b;
    return a;
}

int main(){
    long long a, b;
    cin >> a >> b;
    long long c = a*b;
    long long g = gcd(a, b);
    cout << c/g << endl;
    return 0;
}