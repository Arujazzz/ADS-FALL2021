#include <bits/stdc++.h>
using namespace std;

int find_sqrt(int x){
    int start = 1;
    int end = x;
    int res;
     
    if (x == 0 || x == 1) return x;
    while (start <= end){
        int middle = (start + end)/2;

        if (middle*middle == x) return middle;
        if (middle <= x/middle){
            start = middle + 1; 
            res = middle;
            }
        else end = middle - 1;
    }
    return res;
}

int main (){
    int x;
    cin >>x;
    cout << find_sqrt(x);
    return 0;
}