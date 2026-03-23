#include <bits/stdc++.h>
using namespace std;

//Meet in the middle
class Solution {
int BinarySearch(vector<int>&vec, int num){
    int low=0, high=vec.size()-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(vec[mid]<num){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if (low >= vec.size()) return vec[high]; 
    if (high < 0) return vec[low];
    
    //share the one which is closest to num
    int l= abs(num-vec[low]), h= abs(num-vec[high]);
    if(l<h)return vec[low];
    return vec[high];
}

public:
int minimumDifference(vector<int>& nums) {
    int n=nums.size()>>1;
    vector<vector<int>>left(n+1);
    int totalSum=0;
    for(auto &i : nums)totalSum+=i;
    int halfSum=totalSum>>1;

    //finding all possible subsequences in left half of nums, with k elements
    for(int i=0; i<(1<<n); i++){
        int l_sum=0, cnt=0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                l_sum+=nums[j];
                cnt++;
            }
        }
        left[cnt].push_back(l_sum);
    }

    //sorting for binary search
    for(auto &vec : left){
        sort(vec.begin(), vec.end());
    }

    int ans=INT_MAX;

    //finding subsequences with k elements in right half
    for(int i=0; i<(1<<n); i++){
        int r_sum=0, cnt=0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                r_sum+=nums[j+n];
                cnt++;
            }
        }
        auto &vec = left[n-cnt];
        int num=halfSum-r_sum;
        int l_sum=BinarySearch(vec,num);
        int subs1=l_sum+r_sum, subs2=totalSum-subs1;
        ans=min(ans, abs(subs1-subs2));
    }
    return ans;
}
};


