#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int l = 0, r = 0, zeroes = 0;
    int maxLen = 0;
    while(r < nums.size()){
        if(nums[r] == 0)zeroes++;
        if(zeroes <= k )maxLen = (r-l+1) > maxLen ? (r-l+1) : maxLen;
        else{
            if(nums[l] == 0)zeroes--;
            l++;
        }
        r++;
    }
    return maxLen;
}

int main(){
    vector<int>nums = {0,0,1,1,1,0,0};
    cout << longestOnes(nums,0);
    return 0;
}