#include <bits/stdc++.h>
using namespace std;

bool findMaxSum(vector<int> &arr, int k, int mid){
    vector<int> nums = arr;
    int n = nums.size();
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + nums[i] > mid){
            sum = 0;
            k--;
        }
        if(k==0){
            return false;
        }
        sum+= nums[i];
    }
    return true;
}

int minTime(vector<int>& arr, int k) {
    vector<int> nums = arr;
    int low = *max_element(nums.begin(), nums.end());
    long long high = 0;
    for(int i =0; i< nums.size(); i++){
        high+= nums[i];
    }
    while(low<= high){
        int mid = low+ (high-low)/2;
        bool opinion = findMaxSum(nums, k, mid);
        if(opinion == true){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> vec = {1,2,3,4,5};
    cout << minTime(vec, 2);
    return 0;
}