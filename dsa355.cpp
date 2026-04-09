#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
vector<vector<int>>dp;
int recursion(int i, int j, string &s, string &p){
    //s[i], p[j]
    if(i<1&&j<1)return dp[i][j]=1;
    if(i>=1&&j<1)return dp[i][j]=0;
    if(i< 1 && j >= 1){
        for(int k = 1; k <= j; k++){
            if(p[k-1] != '*') return dp[i][j] = 0;
        }
        return dp[i][j] = 1;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i-1]==p[j-1] || p[j-1]=='?'){
        return dp[i][j]=recursion(i-1, j-1, s, p);
    }else if(p[j-1]=='*'){
        //* = {}
        int notTake = recursion(i, j-1, s,p);
        //* = {1}, took 1 character 
        int take = recursion(i-1, j, s, p);
        if(notTake==1||take==1)return dp[i][j]=1;
        return dp[i][j]=0;
    }
    return dp[i][j]=0;

}

public:
bool isMatch(string &s, string &p) {
    int n1=s.size(), n2=p.size();
    dp.assign(n1+1, vector<int>(n2+1, -1));
    recursion(n1, n2,s,p);
    return dp[n1][n2]==1 ? true : false;
}
};
*/


class Solution {
public:
bool isMatch(string &s, string &p) {
    int nS=s.length(), nP=p.length();
    vector<int>dp(nP+1, 0);
    dp[0]=1;
    int a=0;
    while(a<nP && p[a]=='*'){
        dp[a+1]=1;
        a++;
    }

    for(int i=1; i<=nS; i++){
        vector<int>curr(nP+1, 0);
        for(int j=1; j<=nP; j++){
            if(s[i-1]==p[j-1] || p[j-1]=='?')curr[j]=dp[j-1];
            else if(p[j-1]=='*'){
                //* = {}
                int notTake = curr[j-1];
                //* = {1}, took 1 character 
                int take = dp[j];
                if(notTake==1||take==1)curr[j]=1;
                else curr[j]=0;
            }else curr[j]=0;
        }
        dp=curr;
    }
    return dp[nP]==1 ? true : false;
}
};

