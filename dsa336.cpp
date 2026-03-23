#include <bits/stdc++.h>
using namespace std;


class Solution {
vector<vector<bool>>dp;
public:
bool canPartition(vector<int>& nums) {
    int target=0, n=nums.size();

    for(auto &i : nums)target+=i;
    if(target%2==1)return false;

    vector<bool>dp(target+1,false);
    dp[0]=true;
    dp[nums[0]]=true;

    target = target>>1;
    for(int i=1; i<n; i++){
        vector<bool>tmp(target+1,false);
        tmp[0]=true;
        for(int j=1; j<=target; j++){
            bool notTake=dp[j];
            bool take=false;
            if(j>=nums[i])take=dp[j-nums[i]];
            tmp[j]=take|notTake;
        }
        dp=tmp;
    }
    return dp[target];
    
}
};


