#include <bits/stdc++.h>
using namespace std;


class Solution {
vector<int>parent, rank, connected;
int maxArea=0;

int pathCompression(int a){
    if(parent[a]==a)return a;
    return parent[a]=pathCompression(parent[a]);
}

void unionByRank(int a, int b) {
    int parentA = pathCompression(a), parentB = pathCompression(b);
    if(parentA == parentB)return;

    if(rank[parentA] == rank[parentB]){
        rank[parentA]++;
        parent[parentB]=parentA;
        connected[parentA] += connected[parentB];

    }else if(rank[parentA] < rank[parentB]){
        parent[parentA]=parentB;
        connected[parentB] += connected[parentA];

    }else{
        parent[parentB]=parentA;
        connected[parentA] += connected[parentB];

    }
    
}

void setup(vector<vector<int>>& grid){
    int n= grid.size();

    connected.resize(n*n,1);
    rank.resize(n*n,0);
    parent.resize(n*n, 0);
    for(int i=0; i<(n*n); i++)parent[i]=i;

    vector<int>move_r={-1,0,1,0};
    vector<int>move_c={0,1,0,-1};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cell1 = i*n+j;
            if(grid[i][j]==0)continue;

            for(int k=0; k<4; k++){
                int new_r=i+move_r[k], new_c=j+move_c[k];
                if(new_r<0 || new_r>=n || new_c<0 || new_c>=n)continue;
                if(grid[new_r][new_c]==0)continue;

                int cell2 = new_r*n+new_c;
                unionByRank(cell1, cell2);
            }
            
            int root = pathCompression(cell1);
            maxArea = max(maxArea, connected[root]);
        }
    }

}

public:
int largestIsland(vector<vector<int>>& grid) {
    setup(grid);

    int n=grid.size();

    vector<int>move_r={-1,0,1,0};
    vector<int>move_c={0,1,0,-1};

    int ans=maxArea;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1)continue;

            int area=1;
            set<int>visitedCells;
            for(int k=0; k<4; k++){
                int new_r=i+move_r[k], new_c=j+move_c[k];
                if(new_r<0 || new_r>=n || new_c<0 || new_c>=n)continue;
                if(grid[new_r][new_c]==0)continue;

                int cell = new_r*n+new_c;
                cell = pathCompression(cell);
                if(visitedCells.find(cell) == visitedCells.end()){
                   visitedCells.insert(cell);
                   area+=connected[cell]; 
                }
            }
            ans=max(ans, area);
        }
    }
    return ans;
}

};


