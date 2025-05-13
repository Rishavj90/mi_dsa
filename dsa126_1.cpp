#include <bits/stdc++.h>
using namespace std;

void make_subset(vector<vector<int>>& vec, vector<int>& nums,int i){
    if(i == (1 << nums.size())){
        return;
    }
    vector<int>curr;
    for(int j = 0; j < nums.size(); ++j){
        int n = 1 << j;
        int k = i & n;
        if(k == n){
            curr.push_back(nums[j]);
        }
    }
    vec.push_back(curr);
    make_subset(vec, nums, ++i);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> vec;
    make_subset(vec,nums,0);
    return vec;
}

int main(){
    vector<int> vec = {1,2,3};
    vector<vector<int>> ans = subsets(vec);
    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}