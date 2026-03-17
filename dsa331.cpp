#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size();
    vector<int>dp(n,INT_MAX);

    for(int i=0; i<m; i++){
        vector<int>tmp(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                dp[0]=grid[0][0];
                tmp[0]=dp[0];
                continue;
            }

            int up=dp[j];;
            int left=INT_MAX;
            if(j!=0)left= tmp[j-1];
            
            tmp[j]=grid[i][j]+ min(up, left);
        }
        dp=tmp;
    }
    return dp[n-1];
}
};

int main(){
    vector<vector<int>>grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution sln;
    int ans = sln.minPathSum(grid);
    return 0;
}

