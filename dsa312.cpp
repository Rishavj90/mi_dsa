#include <bits/stdc++.h>
using namespace std;

int pathCompression(vector<int>&parent, int a){
    if(parent[a]==a)return a;
    return parent[a]=pathCompression(parent, parent[a]);
}

int unionByRank(int wgt, int a, int b, vector<int>&Rank, vector<int>&parent) {
    int parentA = pathCompression(parent, a), parentB = pathCompression(parent, b);
    if(parentA == parentB)return 0;

    if(Rank[parentA] == Rank[parentB]){
        Rank[parentA]++;
        parent[parentB]=parentA;

    }else if(Rank[parentA] < Rank[parentB]){
        parent[parentA]=parentB;
    }else{
        parent[parentB]=parentA;
    }
    return wgt;
}

int kruskalsMST(int V, vector<vector<int>> &edges) {
    vector<int>Rank(V, 0);
    vector<int>parent(V, 0);
    for(int i=0; i<V; i++)parent[i]=i;
    
    //weight, node1, node2
    priority_queue<tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>>>minHeap;
    
    for(const auto &vec: edges){
        minHeap.push({vec[2], vec[0], vec[1]});
    }

    int ans=0;
    while(!minHeap.empty()){
        auto [wgt, node1, node2] = minHeap.top();
        minHeap.pop();
        ans+=unionByRank(wgt, node1, node2, Rank, parent);

    }
    return ans;
}


