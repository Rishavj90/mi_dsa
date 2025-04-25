#include <bits/stdc++.h>
using namespace std;

int arrSum(vector<int>& nums, int k){
    int n = nums.size();
    int sum = 0; 
    for(int i = 0; i <n; i++){
        sum+= ceil((double) nums[i]/k);
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, 
        high = *max_element(nums.begin(), nums.end());
    while(low <= high){
        int mid = low + (high-low)/2;
        int sum = arrSum(nums, mid);
        if(sum > threshold){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low; 
}

int main(){
    vector<int> vec = {44,22,33,11,1};
    cout << smallestDivisor(vec, 5);
    return 0;
}