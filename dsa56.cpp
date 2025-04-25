#include <bits/stdc++.h>
using namespace std;

int countFreq(vector<int>& arr, int target) {
    vector<int> nums = arr;
    int low = 0, high = nums.size()-1;
    int lower = nums.size();
    while(low <= high){
        int mid = (long long) (low + high)/2;
        if(nums[mid] >= target){
            lower = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    if(lower == nums.size() || nums[lower] != target){
        return 0;
    }
    int higher = nums.size();
    low = 0, high = nums.size()-1;
    while(low <= high){
        int mid = (long long) (low + high)/2;
        if(nums[mid] > target){
            higher = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return (higher-lower);
}