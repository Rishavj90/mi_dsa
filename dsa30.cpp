#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    int max_num = INT_MIN;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        max_num = max(max_num, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return max_num;
}

int main(){
    vector<int> vec = {5,4,-1,7,8};
    cout << maxSubArray(vec);
    return 0;
}