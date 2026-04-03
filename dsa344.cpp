#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<int>dp(capacity+1, 0);
    
    for(int i=0; i<val.size(); i++){
        int p=val[i], w=wt[i];
        for(int j=w; j<=capacity; j++){
            dp[j]=max(dp[j], dp[j-w]+p);
        }
    }

    return dp[capacity];
}
};



