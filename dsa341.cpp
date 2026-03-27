#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
int recursion(int ind, int sum, vector<int>& nums, int target){
    if(ind>=nums.size()){
        if(sum==target)return 1;
        return 0;
    } 
    int plus=recursion(ind+1,sum+nums[ind],nums,target);
    int minus=recursion(ind+1,sum-nums[ind],nums,target);
    return plus+minus;
}

public:
int findTargetSumWays(vector<int>& nums, int target){
    return recursion(0,0,nums,target); 
}
};
*/

class Solution {
int possiblePartitions(vector<int>&vec, int num){
    auto l= lower_bound(vec.begin(), vec.end(), num);
    auto h= upper_bound(vec.begin(), vec.end(), num);
    return h-l;
}

public:
int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size(), arr_Sum=0;
    int half = (n%2==1)? (n>>1)+1 : (n>>1);
 
    for(auto &i : nums)arr_Sum+=i;

    if(arr_Sum<target || (arr_Sum-target)%2==1)return 0;

    int req=(arr_Sum-target)>>1;

    vector<int>left;
    
    for(int i=0; i<(1<<half); i++){
        int sum=0;
        for(int j=0; j<half; j++){
            if(i&(1<<j)){
                sum+=nums[j];
            }
        }
        left.push_back(sum);
    }

    sort(left.begin(), left.end());

    int ans=0;
    for(int i=0; i<(1<<(n-half)); i++){
        int sum=0;
        for(int j=0; j<(n-half); j++){
            if(i&(1<<j)){
                sum+=nums[half+j];
            }
        }
        ans+= possiblePartitions(left, req-sum);
        
    }
    return ans;

}
};

