#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    int a[100];

    cin>>n>>a[0];

    int max = a[0];
    int min = a[0];

    for (int i=1; i<n; i++){
        cin>>a[i];
        if (a[i] > max) max = a[i];
        else if (a[i] < min) min = a[i];
    }

    for(int i=0;i<n;i++){
        if(a[i] == max) a[i] = min;
        cout<<a[i]<<' ';
        }
    return 0;
}