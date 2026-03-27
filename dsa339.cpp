#include <bits/stdc++.h>
using namespace std;

class Solution {
int possiblePartitions(vector<int>&vec, int num){
    auto l= lower_bound(vec.begin(), vec.end(), num);
    auto h= upper_bound(vec.begin(), vec.end(), num);
    return h-l;
}
public:
int countPartitions(vector<int>& arr, int diff) {
    int n=arr.size(), arr_Sum=0;
    int half = (n%2==1)? (n>>1)+1 : (n>>1);
 
    for(auto &i : arr)arr_Sum+=i;

    if(arr_Sum<diff || (arr_Sum-diff)%2==1)return 0;

    int req=(arr_Sum-diff)>>1;

    vector<int>left;
    
    for(int i=0; i<(1<<half); i++){
        int sum=0;
        for(int j=0; j<half; j++){
            if(i&(1<<j)){
                sum+=arr[j];
            }
        }
        left.push_back(sum);
    }

    sort(left.begin(), left.end());

    int ans=0;
    for(int i=0; i<(1<<(n-half)); i++){
        int sum=0;
        for(int j=0; j<(n-half); j++){
            if(i&(1<<j)){
                sum+=arr[half+j];
            }
        }
        ans+= possiblePartitions(left, req-sum);
        
    }
    return ans;
}
};


