#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
vector<vector<int>>dp;
int recursion(int amount, vector<int>& coins, int ind){
    int n=coins.size();
    if(ind>=n)return 0;
    if(amount<=0)return 1;

    int ways=0;
    for(int i=ind; i<n; i++){
        int coinVal=coins[i];
        int val= amount-coinVal;
        if(val<0)continue;
        if(dp[i][val]==-1)dp[i][val]=recursion(val,coins,i);
        ways+=dp[i][val];
    }
    return dp[ind][amount]=ways;
}
public:
int change(int amount, vector<int>& coins) {
    int n=coins.size();
    if(amount<=0)return 1;
    dp.assign(n, vector<int>(amount+1, -1));
    recursion(amount, coins, 0);
    return dp[0][amount];
}
};
*/

class Solution {
public:
int change(int amount, vector<int>& coins) {
    int n=coins.size();
    vector<unsigned long long>dp(amount+1,0);
    dp[0]=1;

    for(int i=0; i<n; i++){
        vector<unsigned long long>tmp(amount+1,0);
        tmp[0]=1;
        for(int j=1; j<=amount; j++){
            unsigned long long notTake=dp[j];
            unsigned long long take=0;
            if(j>=coins[i])take=tmp[j-coins[i]];
            tmp[j]=take+notTake;
        }
        dp=tmp;
    }
    return dp[amount];
}
};

