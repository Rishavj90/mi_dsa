#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums){
    int n = nums.size();
    set <int> arr;
    for(int i =0; i < n; i++){
        arr.insert(nums[i]);
    }
    
    int longest = 1;
    for(auto it : arr){
        if(arr.find(it-1) == arr.end()){
            int count = 1;
            int num = it;
            while(arr.find(num+1) != arr.end()){
                count++;
                num+=1;
            }
            longest = max(longest, count);
        }
        
    }
    return longest;
}