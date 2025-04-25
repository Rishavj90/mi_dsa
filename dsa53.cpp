#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int low, int high, int target){
    if(low > high) {
        if(high >= 0 && high < nums.size()){
            return high;
        }else{
            return -1;
        }
    }
    int mid = (low + high)/2;
    if(nums[mid] == target){
        return mid;
    }else if(nums[mid] < target){
        return binarySearch(nums,mid+1, high, target);
    }
    return binarySearch(nums, low,mid-1, target);
}

int main(){
    vector<int> vec = {10143, 29122, 30010};
    int ans = binarySearch(vec, 0, vec.size()-1,23112);
    cout << ans;
    return 0;
}
