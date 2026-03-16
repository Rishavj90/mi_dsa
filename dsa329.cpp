#include <bits/stdc++.h>
using namespace std;

//recursive + optimization
/*
class Solution {
private:
vector<vector<long long>>dp;
long long recursion(int i, int j, int m, int n){
    if(i==(m-1) && j==(n-1))return 1;

    //down
    int new_i = i+1, l=0;
    if(new_i<m){
        if(dp[new_i][j]==-1)dp[new_i][j]=recursion(new_i, j,m,n);
        l=dp[new_i][j];
    }

    //right
    int new_j = j+1, r=0;
    if(new_j<n){
        if(dp[i][new_j]==-1)dp[i][new_j]=recursion(i, new_j,m,n);
        r=dp[i][new_j];
    }

    return dp[i][j]=l+r;

}

public:
int uniquePaths(int m, int n) {
    if(m==1 && n==1)return 1;
    dp.assign(m, vector<long long>(n, -1));
    recursion(0,0,m,n);
    return dp[0][0];
}
};
*/

//non-recursive, tabulation
/*
class Solution {
public:
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m, vector<int>(n,-1));
    dp[0][0]=1;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0)continue;
            int up=0;
            if(i!=0)up=dp[i-1][j];
            int left=0;
            if(j!=0)left=dp[i][j-1];
            dp[i][j]=left+up;
        }
    }

    return dp[m-1][n-1];

}
};
*/

//space optimization
class Solution {
public:
int uniquePaths(int m, int n) {
    vector<int>dp(n,0);
    for(int i=0; i<m; i++){
        vector<int>tmp(n, 0);
        tmp[0]=1;
        for(int j=0; j<n; j++){
            if(i==0 && j==0)continue;
            int up=0;
            if(i!=0)up=dp[j];
            int left=0;
            if(j!=0)left=tmp[j-1];
            tmp[j]=left+up;
        }
        dp=tmp;
    }
    return dp[n-1];
}
};



