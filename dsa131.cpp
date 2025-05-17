#include <bits/stdc++.h>
using namespace std;

void make_subset(vector<vector<int>>&vec,vector<int>&nums,vector<int>&curr,int i){
    if(i == nums.size()){
        vec.push_back(curr);
        return;
    }
    curr.push_back(nums[i]);
    make_subset(vec,nums,curr,i+1);
    curr.pop_back();
    while(i+1 != nums.size() && nums[i]==nums[i+1])i++;
    make_subset(vec,nums,curr,i+1);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> vec;
    vector<int> curr;
    sort(nums.begin(), nums.end());
    make_subset(vec,nums,curr,0);
    return vec;
}
int main(){
    vector<int>nums = {1,2,2};
    vector<vector<int>>ans = subsetsWithDup(nums);
    for(auto vec : ans){
        for(auto i : vec){
            cout <<i << " ";
        }
        cout << endl;
    }
    return 0;
}
