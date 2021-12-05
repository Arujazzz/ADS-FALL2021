#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin >>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >>a[i];
    }
    int max = a[0];
    int ans = 0;

    for (int i=0; i<n; i++){
        if (a[i] > max) {
            ans = max;
            max= a[i];
        }
            if (a[i] > ans && a[i] < max){
                ans = a[i];
                }

    }
    cout << ans;
    return 0;
} 