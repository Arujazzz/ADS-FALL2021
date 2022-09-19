#include <iostream>
using namespace std;

int sum(const int* arr, int sz){
    int tot = 0;
    for (int i=0; i<sz; i++){
        tot+=arr[i];
    }
    return tot;
}
void sort(int** mat, int n_rows, int n_col){
    for(int i=0; i<n_rows-1; i++){
        int min=i;
        for(int j=i+1; j<n_rows; j++)
            if (sum(mat[j],n_col) > sum(mat[min], n_col)) 
            min= j;
        auto k=mat[min];
        mat[min]=mat[i];
        mat[i]=k;
    }
}

int main(){
    int n, m;
    cin >> n>>m;
    int** arr = new int*[n];
    for(int i = 0; i < n; i++){
        int* k = new int[m];
        for(int j = 0; j < m; j++){
            cin >> k[j];
        }
        arr[i] = k;
    }
    sort(arr,n,m);
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
            cout <<endl;
    }
    return 0;
}