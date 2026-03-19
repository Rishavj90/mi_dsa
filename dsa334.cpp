#include <bits/stdc++.h>
using namespace std;

//recursion, 3d dp
/*
class Solution {
private:
vector<vector<vector<int>>>dp;
int recursion(int i, int j1, int j2, vector<vector<int>>& grid){
    int n=grid.size(), m=grid[0].size();
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    
    int maxNum=0;
    int newI=i+1;
    for(int a=-1; a<2; a++){
        int newJ1=j1+a;
        if(newJ1<0||newJ1>=m)continue;
        for(int b=-1; b<2; b++){
            int newJ2=j2+b;
            if(newI>=n||newJ2<0||newJ2>=m)continue;

            if(dp[newI][newJ1][newJ2]==-1)dp[newI][newJ1][newJ2]=recursion(newI,newJ1,newJ2,grid);
            maxNum=max(maxNum, dp[newI][newJ1][newJ2]);

        }   
    }
    if(j1==j2)return dp[i][j1][j2]=grid[i][j1]+maxNum;
    return dp[i][j1][j2]=grid[i][j1]+grid[i][j2]+maxNum;
}

public:
int maxChocolate(vector<vector<int>>& grid) {
    int n=grid.size(), m=grid[0].size();
    dp.assign(n,vector<vector<int>>(m,vector<int>(m,-1)));
    recursion(0,0,m-1,grid);
    return dp[0][0][m-1];
}
};
*/


//space optimization
class Solution {
public:
int maxChocolate(vector<vector<int>>& grid) {
    int n=grid.size(), m=grid[0].size();
    vector<vector<int>>dp(m,vector<int>(m,0));
    for(int j1=0; j1<m; j1++){
        for(int j2=0; j2<m; j2++){
            if(j1==j2)dp[j1][j2]=grid[n-1][j1];
            else dp[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        }
    }

    for(int i=n-2; i>=0; i--){
        vector<vector<int>>tmp(m,vector<int>(m,-1));
        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                if(dp[j1][j2]==-1)continue;

                int maxNum=-1;
                for(int a=-1; a<2; a++){
                    int newJ1=j1+a;
                    if(newJ1<0||newJ1>=m)continue;
                    for(int b=-1; b<2; b++){
                        int newJ2=j2+b;
                        if(newJ2<0||newJ2>=m)continue;

                        if(dp[newJ1][newJ2]==-1)continue;
                        maxNum=max(maxNum, dp[newJ1][newJ2]);
                    }   
                }
                if(j1==j2)tmp[j1][j2]=grid[i][j1]+maxNum;
                else tmp[j1][j2]=grid[i][j1]+grid[i][j2]+maxNum;

            }

        }
        dp=tmp;
    }

    return dp[0][m-1];
     
}
};



