#include <bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>>& grid) {
    // 0: sea, 1: land
    int m = grid.size(), n = grid[0].size();

    vector<int>vec(n, 0);
    vector<vector<int>>visited(m, vec);

    for(int i=0; i<m; i++){
        if(grid[i][0] == 1){
            bfs(i,0,visited,grid);
        }
        if(grid[i][n-1] == 1){
            bfs(i,n-1,visited,grid);
        }
    }

    for(int i=0; i<n; i++){
        if(grid[0][i] == 1){
            bfs(0,i,visited,grid);
        }
        if(grid[m-1][i] == 1){
            bfs(m-1,i,visited,grid);
        }
    }

    int ans=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1 && visited[i][j] == 0){
                ans++;
            }
        }
    }
    return ans;

}

// void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
//     int m = grid.size(), n = grid[0].size();
//     visited[i][j] = 1;
//     vector<int>move = {1,0,-1,0};
//     for(int k=0; k<4; k++){
//         int a = i+move[k], b = j+move[3-k];
//         if(a>=0 && a<m && b>=0 && b<n && grid[a][b] == 1 && visited[a][b] == 0){
//             dfs(a,b,visited,grid);
//         }
//     }
//     return;
// }

void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size();

    queue<pair<int,int>>q;
    visited[i][j] = 1;
    q.push({i,j});

    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        
        vector<int>move = {1,0,-1,0};
        for(int k=0; k<4; k++){
            int a = r+move[k], b = c+move[3-k];
            if(a>=0 && a<m && b>=0 && b<n && grid[a][b] == 1 && visited[a][b] == 0){
                q.push({a,b});
                visited[a][b] = 1;
            }
        }

    }
    return;
}


