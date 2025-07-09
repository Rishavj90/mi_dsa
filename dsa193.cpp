#include <bits/stdc++.h>
using namespace std;

int subArrSum(vector<int>& nums, int goal){
    int sum = 0;
    int l = 0, r = 0;
    int TotalArr = 0;
    while(r < nums.size()){
        sum+=nums[r];
        while(sum>0 && sum>goal){
            sum-=nums[l];
            l++;
        }
        if(sum<=goal)TotalArr+=(r-l+1);
        r++;
    }
    return TotalArr;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return subArrSum(nums,goal) - subArrSum(nums,goal-1);
}

int main(){
    vector<int>nums = {0,0,0,0,0};
    cout << numSubarraysWithSum(nums, 0);
    return 0;
}