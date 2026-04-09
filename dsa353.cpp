#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
private:
vector<vector<int>>dp;
int recursion(int i, int j, string &s, string &t){
    //s[i] and t[j]
    if(j<0)return dp[i+1][j+1]=1;
    if(i<0)return dp[i+1][j+1]=0;

    if(s[i]==t[j]){
        if(dp[i][j+1]==-1){
            dp[i][j+1]=recursion(i-1,j,s,t);
        }
        if(dp[i][j]==-1){
            dp[i][j]=recursion(i-1,j-1,s,t);
        }
        return dp[i+1][j+1]=dp[i][j+1]+dp[i][j];
    }else{
        if(dp[i][j+1]==-1){
            dp[i][j+1]=recursion(i-1,j,s,t);
        }
        return dp[i+1][j+1]=dp[i][j+1];
    }
}

public:
int numDistinct(string s, string t) {
    int n1=s.length(), n2=t.length();
    dp.assign(n1+1, vector<int>(n2+1,-1));
    return recursion(n1-1,n2-1,s,t);
}
};
*/

/*
class Solution {
public:
int numDistinct(string s, string t){
    int n1=s.length(), n2=t.length();
    vector<double>dp(n2+1, 0);
    dp[0]=1;
    for(int i=1; i<=n1; i++){
        vector<double>tmp(n2+1, 0);
        tmp[0]=1;
        for(int j=1; j<=n2; j++){
            if(s[i-1]==t[j-1]){
                tmp[j]=dp[j]+dp[j-1];
            }else{
                tmp[j]=dp[j];
            }
        }
        dp=tmp;
    }

    return (int)dp[n2];

}
};
*/


class Solution {
public:
int numDistinct(string s, string t){
    int n1=s.length(), n2=t.length();
    vector<double>dp(n2+1, 0);
    dp[0]=1;
    for(int i=1; i<=n1; i++){
        for(int j=n2; j>0; j--){
            if(s[i-1]==t[j-1]){
                dp[j]+=dp[j-1];
            }
        }
    }
    return (int)dp[n2];
}
};


