#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums){
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;
    vector<int> ans;
    for(int i = 0;i < n; i++){
        if(nums[i] > 0){
            pos.push_back(nums[i]);      
        }else if(nums[i] < 0){
            neg.push_back(nums[i]); 
        }
    }
    int k = min(pos.size(), neg.size());
    for(int i = 0; i < k; i++){
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
    }
    if(pos.size() != k){
        for(int i = pos.size()-k; i < pos.size();i++){
            ans.push_back(pos[i]);
        }
    }else{
        for(int i = neg.size()-k; i < neg.size();i++){
            ans.push_back(neg[i]);
        }
    }

    return ans;
}

int main(){
    vector<int> vec ={28,-41,-22,8,-37,46,35,9,18,6,-19,-26,37,-10,-9,15,14,31};
    vector<int>vec2 = rearrangeArray(vec);
    for(auto i : vec2) cout << i << " ";
    return 0;
}