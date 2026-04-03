#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
int longCommSubstr(string& s1, string& s2) {
    int n1=s1.length(), n2=s2.length();
    vector<int>dp(n2+1,0);

    int maxLen=INT_MIN;

    //1based indexing
    for(int i=1; i<=n1; i++){
        vector<int>curr(n2+1,0);
        for(int j=1; j<=n2; j++){
            if(s1[i-1]==s2[j-1])curr[j]=dp[j-1]+1;
            else curr[j]=0;
            maxLen = max(maxLen, curr[j]);
        }
        dp=curr;
    }

    return maxLen;

}
};


int main(){
    Solution sln;
    string s1="ABCDGH", s2="ACDGHR";
    cout << sln.longCommSubstr(s1, s2);
    return 0;
}

