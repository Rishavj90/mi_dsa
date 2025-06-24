#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int>stk;
    vector<int>ans(nums.size(),0);
    int n = nums.size();
    for(int i = 2*n-1; i >= 0; i--){
        while(!stk.empty() && stk.top() <= nums[i%n])stk.pop();
        if(i < n)ans[i] = (stk.empty()) ? -1 : stk.top(); 
        stk.push(nums[i%n]);
    }
    return ans;
}

int main(){
    vector<int>vec = {1,5,6,8,5,3,2};
    vector<int>vec1 = nextGreaterElements(vec);
    for(auto i : vec1)cout << i << " ";
    return 0;
}