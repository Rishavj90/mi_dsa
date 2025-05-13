#include <bits/stdc++.h>
using namespace std;

void make_subset(vector<vector<int>>& vec,vector<int>& curr, vector<int>& nums,int i){
    if(i >= nums.size()){
        vec.push_back(curr);
        return;
    }
    make_subset(vec, curr, nums, i+1);
    curr.push_back(nums[i]);
    make_subset(vec, curr, nums,i+1);
    curr.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> vec;
    vector<int> curr;
    make_subset(vec,curr,nums,0);
    return vec;
}

int main(){
    vector<int> vec = {1,2,3};
    vector<vector<int>> ans = subsets(vec);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}