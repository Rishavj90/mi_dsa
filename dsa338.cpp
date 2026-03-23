#include <bits/stdc++.h>
using namespace std;

class Solution {
int countOccurrences(int need, vector<int>& left) {
    auto lo = lower_bound(left.begin(), left.end(), need);
    auto hi = upper_bound(left.begin(), left.end(), need);
    return hi - lo;  // number of exact matches
}

public:
int countSubset(vector<int> &arr, int k) {
    int N=arr.size(),n=N>>1;
    if(N%2==1)n+=1;
    vector<int>left;

    for(int i=0; i<(1<<n); i++){
        int sum=0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                sum+=arr[j];
            }
        }
        left.push_back(sum);
    }

    sort(left.begin(), left.end());

    int ans=0;
    for(int i=0; i<(1<<(N-n)); i++){
        int sum=0;
        for(int j=0; j<(N-n); j++){
            if(i&(1<<j)){
                sum+=arr[n+j];
            }
        }
        ans+=countOccurrences(k-sum,left);
        
    }
    return ans;
}
};


