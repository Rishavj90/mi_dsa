#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
int rob(vector<int>&nums){
    int n=nums.size();
    if(n==1)return nums[0];
    int back2=nums[0], back1=max(nums[0], nums[1]); //for 2
    
    for(int i=2; i<n; i++){
        int tmp = max(back1, back2+nums[i]);
        back2=back1;
        back1=tmp;
    }

    return back1;
}

};


