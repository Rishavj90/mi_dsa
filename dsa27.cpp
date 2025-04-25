#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target){
    set<int> ans;
    vector<int> temp;
    for(int i = 0; i < nums.size(); i++){
        int rem = target - nums[i];
        for(int j =0; j < nums.size(); j++){
            if(i == j) continue;
            if(nums[j] == rem){
                ans.insert(i);
                ans.insert(j);
                break;
            }
        }
        if(ans.size() == 2) break;
    }
    for(auto i : ans) temp.push_back(i);
    return temp;
}

int main(){
    vector<int> vec = {3,2,4};
    vector<int> ans = twoSum(vec, 6);
    for(auto i : ans) cout << i << " ";
    return 0;
}