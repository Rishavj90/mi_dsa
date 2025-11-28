#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int time = 0, m = grid.size(), n = grid[0].size();
    time = helper(grid);
    for(int i = 0; i< m; i++){
        for(int j = 0; j< n; j++){
            if(grid[i][j] == 1){
                return -1;
            }
        }
    }
    return time;
}

int helper(vector<vector<int>>&grid){
    int time = 0;
    int m = grid.size(), n = grid[0].size();
    queue<tuple<int,int,int>>q;

    for(int i = 0; i< m; i++){
        for(int j = 0; j< n; j++){
            if(grid[i][j] == 2){
                q.push({i, j,0});
            }
        }
    }

    while(!q.empty()){
        auto [r,c,t] = q.front();
        q.pop();
        time = max(time,t);

        if(r-1 >=0 && grid[r-1][c] == 1){
            grid[r-1][c] = 2;
            q.push({r-1, c,t+1});
        }

        if(r+1 < m && grid[r+1][c] == 1){
            grid[r+1][c] = 2;
            q.push({r+1, c,t+1});
        }
                
        if(c-1 >=0 && grid[r][c-1] == 1){
            grid[r][c-1] = 2;
            q.push({r, c-1,t+1});
        }
                
        if(c+1 < n && grid[r][c+1] == 1){
            grid[r][c+1] = 2;
            q.push({r, c+1,t+1});
        }
    }

    return time;
}



