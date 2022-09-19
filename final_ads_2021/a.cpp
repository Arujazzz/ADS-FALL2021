#include <bits/stdc++.h>
using namespace std;

int n, k;

int k_find(long long sep, vector<long long>& nums){
    long long sum = 0;
    int cnt = 0;
    for(auto i : nums){
        sum += i;
        if(sum > sep){
            sum = i;
            cnt++;
        }
        if(i > sep)
            return (int)1e9;
    }
    if(sum > 0) cnt++;
    
    return cnt;
}

int main(){
    cin >> n;
    cin >> k;
    vector<long long> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    long long l = -1;
    long long min_ = 2e18;
    while(l + 1 < min_){
        long long mid = (l + min_) / 2;
        long long res = k_find(mid, nums);
        if(res <= k)
            min_ = mid;
        else l = mid;
    }
    cout << min_;
}