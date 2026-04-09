#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
vector<vector<int>>dp;
int recursion(int a, int b, string &word1, string &word2){
    //word1[a], word2[b]
    if(b<1)return dp[a][b]=a;
    if(a<1)return dp[a][b]=b;

    if(dp[a][b]!=-1)return dp[a][b];

    if(word1[a-1]!=word2[b-1]){
        int minNum=INT_MAX;
        //insert
        minNum=min(minNum, 1+recursion(a,b-1,word1,word2));
        //remove
        minNum=min(minNum, 1+recursion(a-1,b,word1, word2));
        //replace
        minNum=min(minNum, 1+recursion(a-1,b-1,word1,word2));
        return dp[a][b]=minNum;
    }else{
        return dp[a][b]=recursion(a-1, b-1, word1, word2);
    }
}

public:
int minDistance(string word1, string word2) {
    int n1=word1.length(), n2=word2.length();
    dp.assign(n1+1, vector<int>(n2+1,-1));
    return recursion(n1, n2, word1, word2);
}
};
*/

class Solution {
public:
int minDistance(string word1, string word2) {
    int n1=word1.length(), n2=word2.length();
    vector<int>dp(n2+1, 0);
    for(int i=0; i<=n2; i++)dp[i]=i;

    for(int i=1; i<=n1; i++){
        vector<int>tmp(n2+1, 0);
        tmp[0]=i;
        for(int j=1; j<=n2; j++){
            if(word1[i-1]!=word2[j-1]){
                int minNum=INT_MAX;
                minNum=min(minNum, 1+tmp[j-1]);
                minNum=min(minNum, 1+dp[j]);
                minNum=min(minNum, 1+dp[j-1]);
                tmp[j]=minNum;
            }else{
                tmp[j]=dp[j-1];
            }
        }
        dp=tmp;
    }
    return dp[n2];
}
};


