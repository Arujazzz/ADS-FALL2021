#include <bits/stdc++.h>

using namespace std;

bool bs(vector <int> arr, int m, int x){
    int l = 0;
    int r = m;
    while(l <= r){
        //int m = l + (r - 1) / 2;
        int mid = (l + r ) / 2;
        if(arr[mid] == x) return true;
        if(arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

int main (){

    int n;
    cin >> n;
    vector <int> a;
    int x;
    for (int i=0; i<n; i++){
        cin >>x;
        a.push_back(x);
    }
    
    int m;
    cin >> m;
    vector <int> b;
    int y;
    for (int j=0; j<m; j++){
        cin >>y;
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    if (a.size() > b.size()) swap(a, b);
    for (int i=0; i<a.size(); i++){
        if (bs(b, m, a[i])){
            cout << a[i] << " ";
        } 
    }


    return 0;
}