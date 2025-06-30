#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>ans;  
    deque<int>dq;
    for(int i = 0; i < nums.size(); i++){
        while(!dq.empty() && (i-k) >= dq.front())dq.pop_front();
        while(!dq.empty() && nums[dq.back()] < nums[i])dq.pop_back();
        dq.push_back(i);
        if(i >= k-1)ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main(){
    vector<int>vec = {7,2,4};
    vector<int>ans = maxSlidingWindow(vec,2);
    for(auto i : ans)cout << i << " ";
    return 0;
}