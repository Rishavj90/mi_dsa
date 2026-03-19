#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int minimumTotal(vector<vector<int>>& triangle) {
   int n=triangle.size();
   vector<int>dp(n, INT_MAX);
   dp[0]=triangle[0][0];

   for(int i=1; i<n; i++){
        int a=triangle[i].size();
        vector<int>tmp(n,0);
        for(int j=0; j<a; j++){
            int b=triangle[i-1].size();
            int topLeft = INT_MAX;
            if(j>0 && j<=b)topLeft = dp[j-1];
            int top = INT_MAX;
            if(j<b)top = dp[j];

            tmp[j]=triangle[i][j]+min(topLeft, top);
        }
        dp=tmp;
   }

   return *min_element(dp.begin(), dp.end());

}
};

