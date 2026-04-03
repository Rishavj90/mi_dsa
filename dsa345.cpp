#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
int cutRod(vector<int> &price) {
    int n=price.size();
    vector<int>dp(n+1,0);

    for(int i=0; i<n; i++){
        int l=i+1, p=price[i];
        for(int j=l; j<=n; j++){
            dp[j]=max(dp[j], dp[j-l]+p);
        }
    }
    return dp[n];
}
};



