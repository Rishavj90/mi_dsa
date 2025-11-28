#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int>vec(n,-1);
    vector<vector<int>>ans(m, vec);
    

    queue<tuple<int,int>>q;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(mat[i][j] == 0){
                ans[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();

        vector<int> move = {1,0,-1,0};
        for(int i = 0; i<4; i++){
            int a = r+move[i], b = c+move[3-i];
            if(a<m && a>=0 && b<n && b>=0 && ans[a][b] == -1){
                ans[a][b] = ans[r][c]+1;
                q.push({a,b});
            }
        }

    }
    return ans;
}


