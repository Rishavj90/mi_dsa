#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums){
    int n = nums.size();
    int dip = -1;
    for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            dip = i;
            break;
        }
    }
    if(dip == -1){
        reverse(nums.begin(), nums.end());
    }
    for(int i = n-1; i > dip; i--){
        if(nums[i] > nums[dip]){
            swap(nums[i], nums[dip]);
            break;
        }
    }
    reverse(nums.begin()+dip+1, nums.end());
    return;
}

int main(){
    vector<int> vec = {1,2,3};
    nextPermutation(vec);
    for(auto i : vec) cout << i << " ";
    return 0;
}