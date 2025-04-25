#include <bits/stdc++.h>
using namespace std;

int recursiveSol(vector<int>& nums,int low, int high, int target){
    if(low > high) return low;
    int mid = (long long)(low+high)/2;
    if(nums[mid] == target){
        return mid;
    }else if(nums[mid] > target){
        return recursiveSol(nums, low, mid-1, target);
    }
    return recursiveSol(nums, mid+1, high, target);
}

int searchInsert(vector<int>& nums, int target) {
    return recursiveSol(nums, 0, nums.size()-1, target);
}

int main(){
    vector<int> vec ={1,3,5,6};
    cout << searchInsert(vec, 2);
    return 0;
}