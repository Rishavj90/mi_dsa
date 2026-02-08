#include <bits/stdc++.h>
using namespace std;


class Solution {
vector<int>rank, parent;

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < (n-1))return -1;
        rank.resize(n, 0);
        parent.resize(n,0);
        for(int i=0; i<n; i++)parent[i]=i;

        int extraConnections=0;
        for(const auto &vec : connections){
            int node1=vec[0], node2=vec[1];
            extraConnections+=unionByRank(node1, node2);

        }
        int separateGroups=0;
        for(int i=0; i<n; i++){
            if(parent[i]==i)separateGroups++;
        }
        return (extraConnections>=(separateGroups-1))? separateGroups-1 : -1;

    }
};

