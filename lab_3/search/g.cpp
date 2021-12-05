#include <iostream>

using namespace std;

int bs(int arr[], int l, int r, int x){
    while(l <= r){
        //int m = l + (r - 1) / 2;
        int m = (l + r ) / 2;
        if(arr[m] == x) return m;
        if(arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int bs2(int arr[], int l, int r, int x){
    if(l > r) return -1;
    int m = (l + r) / 2;
    if(arr[m] == x) return m;
    if(arr[m] < x) return bs2(arr, m + 1, r, x);
    return bs2(arr, l, m - 1, x);
}


int main(){

    int n, k;
    cin >>n>>k;
    int a[n];
    int b[k];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int j=0; j<k; j++){
        cin >>b[j];
    }
    for (int j=0; j<k; j++){
        int ans = bs(a, 0, n-1, b[j]);
        if (ans == -1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
} 