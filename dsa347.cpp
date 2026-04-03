#include <bits/stdc++.h>
using namespace std;

/*
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

void recursion(int i, int j, string lcs, string &s1, string &s2, set<string>&ans){
	if(i==0 || j==0){
		reverse(lcs.begin(), lcs.end());
		ans.insert(lcs);
		return;
	}
	
	if(s1[i-1]==s2[j-1] && dp[i][j]==1+dp[i-1][j-1]){
		recursion(i-1, j-1,lcs+s1[i-1],s1,s2,ans);
	}
	if(dp[i-1][j]==dp[i][j]){
		recursion(i-1, j,lcs,s1,s2,ans);
	}
	if(dp[i][j-1]==dp[i][j]){
		recursion(i, j-1,lcs,s1,s2,ans);
	}
	
}

public:
vector<string> allLCS(string &s1, string &s2) {
	int n1=s1.length(), n2=s2.length();
	lcsMatrix(s1, s2);
	set<string> ans;
	recursion(n1, n2, "",s1,s2,ans);
	return vector<string>(ans.begin(), ans.end());
}
};
*/

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
vector<string> allLCS(string &s1, string &s2) {
	int n1=s1.length(), n2=s2.length();
	lcsMatrix(s1, s2);

	vector<set<string>>memo(n2+1);
	for(int i=1; i<=n1; i++){
		vector<set<string>>curr(n2+1);
		for(int j=1; j<=n2; j++){
			//diagonal
			if(s1[i-1]==s2[j-1]&& dp[i][j]==1+dp[i-1][j-1]){
				if(memo[j-1].empty())curr[j].insert(string(1, s2[j-1]));
				else{
					for(auto &str : memo[j-1])curr[j].insert(str+s2[j-1]);
				}
			}

			//up
			if(dp[i][j]==dp[i-1][j]){
				for(auto &str : memo[j])curr[j].insert(str);
			}

			//left
			if(dp[i][j]==dp[i][j-1]){
				for(auto &str : curr[j-1])curr[j].insert(str);
			}
		}
		memo=curr;
	}
	return vector<string>(memo[n2].begin(), memo[n2].end());
}
};


