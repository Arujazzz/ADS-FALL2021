#include <bits/stdc++.h>
using namespace std;
vector<string> findRelativeRanks(vector<int>& nums) {
    vector<pair<int,int>> temp;
    int n = nums.size();
    for(int i=0;i<n;i++){
        temp.push_back(make_pair(nums[i], i));
    }
    sort(temp.rbegin(), temp.rend());
    vector<string> answer(n);
    answer[temp[0].second] = "Gold Medal";
    if(n>=2){
        answer[temp[1].second] = "Silver Medal";
    }
    if(n>=3){
        answer[temp[2].second] = "Bronze Medal";
    }
    for(int i=3;i<n;i++)
        answer[temp[i].second] = to_string(i+1);
    return answer;
}
int main(){
    int n;
    vector<int> nums;;
    cin >> n;
    int score;
    for (int i=0; i<n; i++){
        cin >>score;
        nums.push_back(score);
    }
    vector<string> answer = findRelativeRanks(nums);
    for(auto x: answer)cout<<x<<" ";
}