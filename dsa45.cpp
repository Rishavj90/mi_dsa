#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i-1] == nums[i]) continue;
        for(int j = i+1; j < n; j++){
            if(j > i+1 && nums[j-1] == nums[j]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l){
                int sum = nums[i] + nums[j];
                sum+= nums[k];
                sum+= nums[l];
                if(sum > target){
                    l--;
                }else if(sum < target){
                    k++;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while(nums[k] == nums[k-1] && k < l) k++;
                    while(nums[l] == nums[l+1] && k < l) l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {0,0,4,-2,-3,-2,-2,-3};
    vector<vector<int>> vec2 = fourSum(vec, -1);
    for(auto i : vec2){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}