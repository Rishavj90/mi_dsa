#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n=val.size();
    vector<int>dp(W+1, 0);

    for(int i=0; i<n; i++){
        int w=wt[i], p=val[i];
        vector<int>tmp(W+1, 0);
        for(int j=0; j<w; j++)tmp[j]=dp[j];
        for(int j=w; j<=W; j++){
            tmp[j]=max(dp[j], dp[j-w]+p);
        }
        dp=tmp;
    }

    return dp[W];
}
};


int main(){
    Solution sln;
    vector<int>wt = {1,7,9}, val = {10,8,6};
    cout << sln.knapsack(7,val,wt);
    return 0;
}

