#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n= nums.size();
    if(n==1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-2] < nums[n-1]) return (n-1);
    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1]){
            high = mid -1;
        }else if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
            return mid;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> vec = {1,5,3,4,7,6};
    cout << findPeakElement(vec);
    return 0;
}