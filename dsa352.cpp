#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
vector<vector<int>>dp;
void lcsMatrix(string &s1, string &s2){
	int n1=s1.length(), n2=s2.length();
	dp.assign(n1+1, vector<int>(n2+1,0));

	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2; j++){
			if(s1[i-1]!=s2[j-1])dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			else dp[i][j]=1+dp[i-1][j-1];
		}
	}
}

public:
string shortestCommonSupersequence(string str1, string str2) {
    lcsMatrix(str1, str2);
    int n1=str1.length(), n2=str2.length();
    int i=n1, j=n2;

    string ans="";
    while(i>0&&j>0){
        if(str1[i-1]==str2[j-1]){
            ans+=str1[i-1];
            i--; j--;
        }else if(dp[i-1][j]>=dp[i][j-1]){
            ans+=str1[i-1];
            i--;
        }else{
            ans+=str2[j-1];
            j--;
        }
    }
    while(i>0){
        ans+=str1[i-1];
        i--;
    }
    while(j>0){
        ans+=str2[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;

}
};


