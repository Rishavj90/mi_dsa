#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    map<int, int> mpp;
    mpp[0] =1;
    int sum =0, count =0;
    for(int i =0; i < n; i++){
        sum += nums[i];
        count += mpp[sum-k];
        mpp[sum] += 1;
    }
    return count;
}
int main(){
    vector<int> vec = {-1,1,0};
    cout << subarraySum(vec, 0);
    return 0;
}