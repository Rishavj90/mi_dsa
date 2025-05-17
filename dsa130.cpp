#include <bits/stdc++.h>
using namespace std;

void make_subset(vector<int>&vec,vector<int>&nums, vector<int>&curr, int i, int sum){
    if(i == nums.size()){
        vec.push_back(sum);
        return;
    }
    curr.push_back(nums[i]);
    make_subset(vec,nums,curr,i+1,sum+nums[i]);
    curr.pop_back();
    make_subset(vec,nums,curr,i+1,sum);
}

vector<int> subsetSums(vector<int>& nums) {
    vector<int> vec;
    vector<int> curr;
    make_subset(vec,nums,curr,0,0);
    return vec;
}

int main(){
    vector<int> vec = {1,4};
    vector<int>ans = subsetSums(vec);
    for(auto i : ans){
        cout <<i << " ";
    }
    return 0;
}