#include <bits/stdc++.h>
using namespace std;

class Solution {
unordered_map<int, int>parent, rank;

int pathCompression(int a){
    if(parent[a]==a)return a;
    return parent[a]=pathCompression(parent[a]);
}

int unionByRank(int a, int b) {
    int parentA = pathCompression(a), parentB = pathCompression(b);
    if(parentA == parentB)return 1;

    if(rank[parentA] == rank[parentB]){
        rank[parentA]++;
        parent[parentB]=parentA;

    }else if(rank[parentA] < rank[parentB]){
        parent[parentA]=parentB;
    }else{
        parent[parentB]=parentA;
    }
    return 0;
}

public:
int removeStones(vector<vector<int>>& stones) {
    int rows=0, columns=0;
    for(auto &vec : stones){
        rows=max(rows, vec[0]);
        columns=max(columns, vec[1]);
    }
    int n=rows+columns+2;
    
    for(int i=0; i<n; i++){
        parent[i]=i;
        rank[i]=0;
    }

    for(auto &vec : stones){
        int r=vec[0], c=rows+1+vec[1];
        unionByRank(r,c);
    }

    set<int> uniqueRoots;
    for(auto &vec : stones){
        int r = vec[0];
        uniqueRoots.insert(pathCompression(r));
    }
    int groups = uniqueRoots.size();
    return (stones.size()-groups);

}

};


