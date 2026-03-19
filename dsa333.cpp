#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int minFallingPathSum(vector<vector<int>>& mat) {
    int n=mat.size();
    vector<int>dp;
    dp.assign(mat[0].begin(), mat[0].end());

    for(int i=1; i<n; i++){
        vector<int>tmp(n,0);
        for(int j=0; j<n; j++){
            vector<int>var(3,INT_MAX);
            if(j!=0) var[0]=dp[j-1];
            var[1]=dp[j];
            if(j!=(n-1)) var[2]=dp[j+1];

            int minVal=INT_MAX;
            for(auto &i : var)minVal= min(minVal, i);
            tmp[j]=mat[i][j]+minVal;
        }
        dp=tmp;
    }

    return *min_element(dp.begin(), dp.end());    
}
};



