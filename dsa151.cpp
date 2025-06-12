#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = 1 << nums.size();
    for(int i = 0; i < n; ++i){
        vector<int>temp;
        for(int a = 0; a < nums.size(); ++a){
            int k = i >> a;
            if(k == 0)break;
            if((k&1)==1)temp.push_back(nums[a]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>>ans = subsets(nums);
    for(auto vec : ans){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}