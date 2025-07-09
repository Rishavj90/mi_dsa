#include <bits/stdc++.h>
using namespace std;

int NiCeSubArr(vector<int>& nums, int k){
    if(k < 0)return 0;
    int ans = 0;
    int l = 0, r= 0;
    int odds = 0;
    while(r < nums.size()){
        if(nums[r]%2 == 1)odds++;
        if(odds > k){
            while(nums[l]%2 == 0)l++;
            l++;
            odds--;
        }
        if(odds <= k)ans += (r-l+1);
        r++;
    }
    return ans;
} 


int numberOfSubarrays(vector<int>& nums, int k) {
    return NiCeSubArr(nums, k) - NiCeSubArr(nums, k-1);
}

int main(){
    vector<int>nums = {1,1,2,1,1};
    cout << numberOfSubarrays(nums, 3);
    return 0;
}