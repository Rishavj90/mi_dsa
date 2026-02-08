#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n= grid.size();
    if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
    if(n == 1) return 1;

    int pathLen=1;

    queue<tuple<int,int>>q;
    q.push({0,0});
    grid[0][0] = 1;

    vector<int>moveX = {-1,-1,-1,0,0,1,1,1};
    vector<int>moveY = {-1,0,1,-1,1,-1,0,1};

    while(!q.empty()){
        int a=q.size();
        for(int i=0; i<a; i++){
            auto [nodeX, nodeY] = q.front();
            q.pop();
            if(nodeX==(n-1) && nodeY==(n-1))return pathLen;

            for(int j=0; j<8; j++){
                int newX = nodeX+moveX[j], newY = nodeY+moveY[j];  
                if(
                    newX >=0 && newX <n &&
                    newY >=0 && newY <n &&
                    grid[newX][newY]==0
                ){
                    q.push({newX, newY});
                    grid[newX][newY] = 1;
                    
                }
            }
        }
        pathLen++;

    }
    return -1;
}

