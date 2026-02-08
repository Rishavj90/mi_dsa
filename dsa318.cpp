#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
vector<vector<int>>timeGrid;

void dijkstra(vector<vector<int>>& grid){
    int n=grid.size();
    timeGrid.resize(n, vector<int>(n,INT_MAX));
    timeGrid[0][0] = grid[0][0];

    priority_queue<tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
                    greater<tuple<int, int, int>>>minHeap;

    //time, row, column
    minHeap.push({grid[0][0], 0, 0});

    vector<int>move_r={-1,0,1,0};
    vector<int>move_c={0,1,0,-1};

    while(!minHeap.empty()){
        auto [time, r, c] = minHeap.top();
        minHeap.pop();
        if(r==(n-1) && c==(n-1))return;

        if(timeGrid[r][c]<time)continue;
        
        for(int i=0; i<4; i++){
            int new_r=r+move_r[i], new_c=c+move_c[i];
            if(new_r<0 || new_r>=n || new_c<0 || new_c>=n)continue;
            int newTime = max(time, grid[new_r][new_c]);

            if(newTime < timeGrid[new_r][new_c]){
                timeGrid[new_r][new_c] = newTime;
                minHeap.push({newTime, new_r, new_c});

            }
        }

    }

}

public:
int swimInWater(vector<vector<int>>& grid) {
    int n=grid.size();
    dijkstra(grid);
    return timeGrid[n-1][n-1];
}

};
*/

class Solution {
vector<int>parent, rank;
vector<tuple<int,int,int>>sortedTime;

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

    }else if(rank[parentA] < rank[parentB]){
        parent[parentA]=parentB;
    }else{
        parent[parentB]=parentA;
    }
    
}

public:
int swimInWater(vector<vector<int>>& grid) {
    int n=grid.size();

    rank.resize(n*n, 0);
    sortedTime.resize(n*n);
    parent.resize(n*n, 0);
    for(int i=0; i<(n*n); i++){
        parent[i]=i;
        int r=i/n, c=i%n;
        sortedTime[i]={grid[r][c],r,c};
    }
    sort(sortedTime.begin(), sortedTime.end());

    vector<int>moveR={-1,0,1,0};
    vector<int>moveC={0,1,0,-1};
    
    for(auto [timeVar, r,c] : sortedTime){
        int node = n*r+c;

        for(int i=0; i<4; i++){
            int newR = r+moveR[i], newC = c+moveC[i];
            if(newR<0 || newR>=n || newC<0 ||newC>=n)continue;

            int newTime = grid[newR][newC];
            if(newTime <=timeVar){
                int newNode = n*newR+newC;
                unionByRank(node, newNode);
            }
        }
        if(pathCompression(0) == pathCompression(n*n-1))return timeVar;

    }
    return -1;
    
}

};


