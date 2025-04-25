#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums){
    int n = nums.size();
    map<int, int> countMpp;
    for(int i = 0; i < n; i++){
        countMpp[nums[i]]++;
    }
    int max_freq = 0;
    int ans;
    for(auto i : countMpp){
        if(i.second > max_freq){
            max_freq = i.second;
            ans = i.first;
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {2,2,1,1,1,2,2};
    cout << majorityElement(vec);
    return 0;
}