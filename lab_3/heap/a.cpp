#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMax() {
        return a[0];
    }

    void siftUp(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
            
        }
    }
    
    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        heapify(i);
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);
        if (right(i) < a.size() && a[left(i)] < a[right(i)])
            j = right(i);
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMin() {
        int root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
    }

    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        //siftUp(i);
        sift(i);
    }

    void print() {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
    }
};



int main (){
    MaxHeap *heap = new MaxHeap();
    
    vector <int> v, v2;
    int n;
    cin >> n;
    int arr[n];
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        heap -> insert(arr[i]);
        
    }
    int new_v = 0;
    int ans = 0;
    int k;
    cin >> k;
    int a, b;
    while(k>0){
        cin >> a >> b;
        for (int i=1; i<=n; i++){
            if (i == a){
                new_v = b + arr[i];
                heap -> increaseKey(a - 1 , new_v); 
                v.push_back(new_v);               
            }
        }
        k--;
    }
    heap -> print();
    for (int j=0; j<v.size(); j++){
        cout << v[j] <<" ";
    }

    return 0;
}