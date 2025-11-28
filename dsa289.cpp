#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>> &grid){
    int m=grid.size(), n=grid[0].size();
    vector<vector<int>>visited(m, vector<int>(n, 0));

    int ans=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '1' && visited[i][j] == 0){
                dfs(i,j,visited, grid);
                ans++;
            }
        }
    }
    return ans;

}

void dfs(int a, int b, vector<vector<int>> &visited, vector<vector<char>> &grid){
    int m=grid.size(), n=grid[0].size();
    visited[a][b] = 1;

    int move_r[] = {-1,-1,-1,0,0,1,1,1};
    int move_c[] = {-1,0,1,-1,1,-1,0,1};

    for(int i=0; i<8; i++){
        int r = a+move_r[i], c = b+move_c[i];
        if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == '1' && visited[r][c] == 0){
            dfs(r,c,visited, grid);
        }
    }
}



