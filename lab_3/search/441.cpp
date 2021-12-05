#include <bits/stdc++.h>
using namespace std;

int arrangecoins(int x){
    int l = 1;
    int r = x;
    while (l <= r){
        int mid = (l+r)/2;
        int curr = (mid*(mid + 1))/2;
        if (curr == x) return mid;
        if (curr > x) r = mid -1;
        else l = mid + 1;
    }
    return r;
}

int main (){
    int n;
    cin >> n;
    cout << arrangecoins(n);
    return 0;
} 