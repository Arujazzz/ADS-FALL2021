#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int target, int n){
    int start = 0;
    int end = n-1;
    
    while (start <= end){
        int middle = (start + end)/2;
        if (arr[middle] == target) return middle;
        else if (arr[middle] < target) start = middle + 1;
        else middle = end - 1;
    }
    return end + 1;
}

int main (){
    int n;
    cin >>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int k;
    cin >>k;
    cout << search (a, k, n);
    return 0;
}