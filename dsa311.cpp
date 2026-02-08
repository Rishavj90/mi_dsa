#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
//vec stores Rank or Size
vector<int>Rank, Size, parent;

int pathCompression(int u){
    if(parent[u]==u)return u;
    return parent[u]=pathCompression(parent[u]);
}

public:

DisjointSet(int n) {
    Rank.resize(n,0);
    Size.resize(n,1);
    parent.resize(n);
    for(int i=0; i<n; i++){
        parent[i]=i;
    }
}

bool find(int u, int v) {
    int parent_u = pathCompression(u), parent_v = pathCompression(v);
    return (parent_u==parent_v) ? true : false;
    //or return pathCompression(u) == pathCompression(v);
}

void unionByRank(int u, int v) {
    int parent_u = pathCompression(u), parent_v = pathCompression(v);
    if(parent_u == parent_v)return;

    if(Rank[parent_u] == Rank[parent_v]){
        int smallParent = min(parent_u, parent_v), bigParent = max(parent_u, parent_v);
        parent[bigParent]=smallParent;
        Rank[smallParent]++;

    }else{
        int BigRank=0, SmallRank=0;
        if(Rank[parent_u] < Rank[parent_v]){
            BigRank=parent_v;
            SmallRank=parent_u;
        }else{
            BigRank=parent_u;
            SmallRank=parent_v;
        }
        parent[SmallRank]=BigRank;
    }
}

void unionBySize(int u, int v) {
    int parent_u = pathCompression(u), parent_v = pathCompression(v);
    if(parent_u == parent_v)return;

    if(Size[parent_u] == Size[parent_v]){
        int smallParent = min(parent_u, parent_v), bigParent = max(parent_u, parent_v);
        parent[bigParent]=smallParent;
        Size[smallParent]+=Size[bigParent];
    }else{
        int BigSize=0, SmallSize=0;
        if(Size[parent_u] < Size[parent_v]){
            BigSize=parent_v;
            SmallSize=parent_u;
        }else{
            BigSize=parent_u;
            SmallSize=parent_v;
        }
        parent[SmallSize]=BigSize;
        Size[BigSize]+=Size[SmallSize];
    }
}
};


