#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int>mpp;
    vector<int>nge;
    stack<int>stk;

    for(int i = nums2.size()-1; i >= 0; i--){
        while(!stk.empty() && stk.top()< nums2[i])stk.pop();
        if(!stk.empty())mpp[nums2[i]] = stk.top();
        else mpp[nums2[i]] = -1;
        stk.push(nums2[i]);
    }
    vector<int>ans;
    for(auto i : nums1){
        ans.push_back(mpp[i]);
    }
    return ans;
}

int main(){
    vector<int>vec1 = {4,1,2};
    vector<int>vec2 = {1,3,4,2};
    vector<int>vec3 = nextGreaterElement(vec1, vec2);
    for(auto i : vec1)cout << i << " ";
    cout << endl;
    for(auto i : vec2)cout << i << " ";
    cout << endl;
    for(auto i : vec3)cout << i << " ";
    return 0;
}