#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int frogJump(vector<int>& heights, int k) {
    int n= heights.size();
    vector<int>dp(n, 0);

    for(int i=1; i<n; i++){
        int newMin=INT_MAX;
        for(int j=1; j<=k; j++){
            int a= i-j;
            if(a<0)break;
            int tmp = dp[a]+abs(heights[a]-heights[i]);
            newMin = min(newMin, tmp);
        }
        dp[i]=newMin;
    }
    return dp[n-1];
    
}
};


