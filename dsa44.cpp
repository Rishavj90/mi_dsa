#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i =0; i < n; i++){
        while(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1, k = n-1;
        while(j < k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum < 0){
                j++;
            }else if(sum > 0){
                k--;
            }else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--; 
            }
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {1,1,1};
    vector<vector<int>> vec2 = threeSum(vec);
    for(auto i : vec2){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}