#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    int count1 = 0, count2 = 0;

    int el1 = 0, cnt1 = 0;
    int el2 = 0, cnt2 = 0;
    for(int i =0; i < n; i++){
        if(cnt1 == 0 && nums[i] != el2){
            cnt1++;
            el1 = nums[i];
        }else if(cnt2 == 0 && nums[i] != el1){
            cnt2++;
            el2 = nums[i];
        }else if(el1 == nums[i]) cnt1++;
         else if(el2 == nums[i]) cnt2++;
         else{
            cnt1--;
            cnt2--;
         }
    }

    for(int i = 0; i < n; i++){
        if(el1 == nums[i]) count1++;
        else if(el2 == nums[i]) count2++;
    }
    if(count1 > n/3) ans.push_back(el1);
    if(count2 > n/3) ans.push_back(el2);
    return ans;
}

int main(){
    vector<int> vec = {1,1,3,3,2,2,1};
    vector<int> vec2 = majorityElement(vec);
    for(auto i : vec2) cout << i << " ";
    return 0;
}