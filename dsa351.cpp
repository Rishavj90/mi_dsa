#include <bits/stdc++.h>
using namespace std;


class Solution {
int lcs(string &s1, string &s2) {
    vector<int>dp(s1.length()+1,0);
    vector<int>curr(s1.length()+1,0);

    for(int i=0; i<s2.length(); i++){
        for(int j=0; j<s1.length(); j++){
            int dp_i=i+1, dp_j=j+1;
            if(s2[i]!=s1[j])curr[dp_j]=max(curr[dp_j-1], dp[dp_j]);
            else curr[dp_j]=1+dp[dp_j-1];
            
        }
        dp=curr;
    }

    return dp[s1.length()];
}
public:
int minDistance(string word1, string word2) {
    int n=lcs(word1, word2);
    int del1= word1.length()-n, del2= word2.length()-n;
    return del1+del2;
}
};

