#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
    int ans = INT_MAX, ans1 = 0;
    int low = 0, high = nums.size()-1;
    while(low <= high){
        int mid = (long long)(low+high)/2;
        if(nums[low] <= nums[mid]){
            ans = min(ans,nums[low]);
            if(ans == nums[low]) ans1 = low;
            low = mid+1;
        }else{
            ans = min(ans,nums[mid]);
            if(ans == nums[mid]) ans1 = mid;
            high = mid-1;
        }
    }
    return ans1;
}

int main(){
    vector<int> vec = {8, 10, 21, 31, 43, 45};
    cout << findMin(vec);
    return 0;
}