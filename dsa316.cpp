#include <bits/stdc++.h>
using namespace std;

class Solution {
vector<int>parent, rank;

int pathCompression(int a){
    if(parent[a]==a)return a;
    return parent[a]=pathCompression(parent[a]);
}

int unionByRank(int a, int b) {
    int parentA = pathCompression(a), parentB = pathCompression(b);
    if(parentA == parentB)return 0;

    if(rank[parentA] == rank[parentB]){
        rank[parentA]++;
        parent[parentB]=parentA;

    }else if(rank[parentA] < rank[parentB]){
        parent[parentA]=parentB;
    }else{
        parent[parentB]=parentA;
    }
    return -1;
}

public:
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    vector<vector<int>>grid(n, vector<int>(m,0));

    rank.resize(n*m, 0);
    parent.resize(n*m, 0);    
    for(int i=0; i<(n*m); i++)parent[i]=i;
    
    vector<int>move_r = {-1,0,1,0}, move_c = {0,1,0,-1};

    vector<int>ans;
    int count=0;
    for(const auto &vec : operators){
        int r=vec[0], c=vec[1];
        if(grid[r][c] != 1){
            count++;
            grid[r][c]=1;
        }else{
            ans.push_back(count);
            continue;
        }

        for(int i=0; i<4; i++){
            int new_r = r+move_r[i], new_c = c+move_c[i];
            if(new_r<0 || new_r>=n || new_c<0 || new_c>=m)continue;
            if(grid[new_r][new_c] != 1) continue;
            int cell1 = r*m+c, cell2 = new_r*m+new_c;
            count += unionByRank(cell1, cell2);
        }

        ans.push_back(count);

    }
    return ans;

}

};

