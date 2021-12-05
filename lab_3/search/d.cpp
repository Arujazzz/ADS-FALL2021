#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
    int n,m, s, k = 0;
    cin >>m >>n;
    int a[m][n];
    int aa[m];
    int bb[n];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    for(int i = 0; i < m; ++i){
        s = a[i][0];
        for(int j = 1; j < n; ++j)
            if(s > a[i][j])
                s = a[i][j];
        aa[i] = s;
    }
    for(int i = 0; i < n; ++i){
        s = a[0][i];
        for(int j = 1; j < m; ++j)
            if(s < a[j][i])
                s = a[j][i];
        bb[i] = s;
    }
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(aa[i] == bb[j])
                ++k;
    cout << k;
    return 0;
}