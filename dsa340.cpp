#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
vector<int>dp;
int recursion(vector<int>& coins, int amount){
    if(amount<=0)return 0;

    int minVal=INT_MAX;
    for(auto &val : coins){
        if(amount>=val){
            if(dp[amount-val]==-2)dp[amount-val]= recursion(coins, amount-val);
            int tmp=dp[amount-val];
            if(tmp!=-1)minVal=min(minVal, 1+tmp);
        }
    }
    if(minVal==INT_MAX)return -1;
    return minVal;
    
}

public:
int coinChange(vector<int>& coins, int amount) {
    dp.assign(amount+1,-2);
    dp[amount]= recursion(coins,amount);
    return dp[amount];
}
};
*/

class Solution {
public:
int coinChange(vector<int>& coins, int amount) {
    vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;

    for(int i=1; i<=amount; i++){
        for(auto &j : coins){
            if(j>i || dp[i-j]==INT_MAX)continue;
            dp[i] = min(dp[i], 1+dp[i-j]);
        }
    }

    return (dp[amount]==INT_MAX) ? -1 : dp[amount];
}
};


