#include <bits/stdc++.h>
using namespace std;

int AlmostGoodSubArr(vector<int>& nums, int k){
    int l = 0,r = 0;
    int unq = 0;
    int goodSubArr = 0;
    vector<int>alp(nums.size()+1,0);
    while(r < nums.size()){
        int i = nums[r];
        if(alp[i] == 0)unq++;
        alp[i]++;
        while(unq > k){
            int j = nums[l];
            alp[j]--;
            if(alp[j] == 0)unq--;
            l++;
        }
        if(unq<=k)goodSubArr+=(r-l+1);
        r++;
    }
    return goodSubArr;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return AlmostGoodSubArr(nums, k) - AlmostGoodSubArr(nums, k-1);
}

int main(){
    vector<int>nums = {1,2,1,3,4};
    cout << subarraysWithKDistinct(nums, 3);
    return 0;
}