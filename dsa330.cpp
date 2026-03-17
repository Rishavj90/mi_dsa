#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=obstacleGrid.size(), m=obstacleGrid[0].size();
    if(obstacleGrid[n-1][m-1]==1)return 0;
    vector<int>dp(m, 0);
    dp[0]=1;

    for(int i=0; i<n; i++){
        vector<int>tmp(m,0);
        tmp[0]=1;
        for(int j=0; j<m; j++){
            if(i==0 && j==0)continue;
            int up=0;
            if(i!=0 && obstacleGrid[i-1][j]==0)up=dp[j];
            int left=0;
            if(j!=0 && obstacleGrid[i][j-1]==0)left=tmp[j-1];
            tmp[j]=up+left;
        }
        dp=tmp;
    }
    return dp[m-1];
}
};


