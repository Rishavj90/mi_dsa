#include <bits/stdc++.h>
using namespace std;

class Solution {
int hlpFunc(int start, int end, vector<int>& nums){
    int n=nums.size();
    if(n==1)return nums[0];
    int back2=0, back1=0; 
    
    for(int i=start; i<=end; i++){
        int tmp = max(back1, back2+nums[i]);
        back2=back1; 
        back1=tmp;
    }

    return back1;
}

public:
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)return nums[0];
    if(n==2)return max(nums[0], nums[1]);
    return max(hlpFunc(0, n-2, nums), hlpFunc(1, n-1, nums));
}
};


