#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
int maximumPoints(vector<vector<int>>& mat){
    int n=mat.size(), m=mat[0].size();
    vector<int>prev(mat[0].begin(), mat[0].end());
    
    for(int i=1; i<n; i++){
        vector<int>tmp(m,INT_MIN);
        for(int j=0; j<m; j++){
            for(int k=0; k<m; k++){
                if(j==k)continue;
                tmp[j] = max(tmp[j], mat[i][j]+prev[k]);
            }
        }

        prev=tmp;
    }
    int ans=INT_MIN;
    for(auto &i : prev)ans=max(ans, i);
    return ans;
}
};



