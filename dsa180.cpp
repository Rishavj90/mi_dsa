#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater_left(vector<int>& nums){
    vector<int>ngL(nums.size(), 0);
    stack<int>stk;
    for(int i = 0; i < nums.size(); i++){
        while(!stk.empty() && nums[i] < nums[stk.top()])stk.pop();
        ngL[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    return ngL;
}
vector<int> nextGreater_right(vector<int>& nums){
    vector<int>ngR(nums.size(), 0);
    stack<int>stk;
    for(int i = nums.size() -1; i >=0; i--){
        while(!stk.empty() && nums[i] <= nums[stk.top()])stk.pop();
        ngR[i] = stk.empty() ? nums.size() : stk.top();
        stk.push(i);
    }
    return ngR;
}
vector<int> nextSmaller_left(vector<int>& nums){
    vector<int>nsL(nums.size(), 0);
    stack<int>stk;
    for(int i = 0; i < nums.size(); i++){
        while(!stk.empty() && nums[i] > nums[stk.top()])stk.pop();
        nsL[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    return nsL;
}
vector<int> nextSmaller_right(vector<int>& nums){
    vector<int>nsR(nums.size(), 0);
    stack<int>stk;
    for(int i = nums.size() -1; i >=0; i--){
        while(!stk.empty() && nums[i] >= nums[stk.top()])stk.pop();
        nsR[i] = stk.empty() ? nums.size() : stk.top();
        stk.push(i);
    }
    return nsR;
}

long long subArrayRanges(vector<int>& nums) {
    vector<int>ngL = nextGreater_left(nums);
    vector<int>ngR = nextGreater_right(nums);
    vector<int>nsL = nextSmaller_left(nums);
    vector<int>nsR = nextSmaller_right(nums);

    long long ans = 0;
    for(int i = 0; i < nums.size(); i++){
        long long min_l = i - ngL[i], min_r = ngR[i] - i;
        long long max_l = i - nsL[i], max_r = nsR[i] - i;
        long long res = (max_l*max_r - min_l*min_r)*nums[i];
        ans += res;   
    }
    return ans;
}