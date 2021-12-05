#include <bits/stdc++.h>
using namespace std;

bool perfect_sqrt(int x){
    int start = 1;
    int end = x;
    int res;
     
    if (x == 0 || x == 1) return true;
    while (start <= end){
        int middle = (start + end)/2;

        if (middle*middle == x) return true;
        if (middle <= x/middle){
            start = middle + 1; 
            }
        else end = middle - 1;
    }
    return false;
}

int main (){
    int x;
    cin >>x;
    if (perfect_sqrt(x)) cout << "true";
    else cout << "false";
    return 0;
}