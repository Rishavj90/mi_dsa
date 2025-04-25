#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (long long)(low + high)/2;
        if(nums[mid] == target){
            return true;
        }else if(nums[mid] == nums[low] && nums[mid] == nums[high]){
            low++, high--;
        }else if(nums[low] <= nums[mid]){
            if(nums[low] <= target && nums[mid]>= target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            if(nums[mid] <= target && nums[high]>= target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> vec = {1,0,1,1,1};
    cout << search(vec, 0);
    cout << endl << true << " : True";
    return 0;
}