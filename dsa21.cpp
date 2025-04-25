#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums){
    int n = nums.size();
    int ans;
    for(int i = 0; i < n; ++i){
        int check = 0;
        for(int j = 0; j < n; ++j){
            if(nums[i] == nums[j]) check++;
        }
        if(check == 1){
            ans = nums[i];
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {1};
    cout << singleNumber(vec);
    return 0;    
}