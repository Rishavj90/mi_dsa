#include <bits/stdc++.h>
using namespace std;

//by rank
class disjointSetUnion{
    vector<int>rank, parent;
    public:
    disjointSetUnion(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0; i< parent.size(); i++)parent[i]=i;
    }

    int pathCompress(int a){
        if(a == parent[a])return a;
        return parent[a] = pathCompress(parent[a]);
    }

    void unionSet(int a, int b){
        //check rank of their parents
        //update rank of their parents
        //compress their path

        int par_a = parent[a];
        int par_b = parent[b];

        if(rank[par_a] < rank[par_b]){
            rank[par_b]++;
            parent[par_a] = parent[par_b];
            pathCompress(par_a);
        }else{
            rank[par_a]++;
            parent[par_b] = parent[par_a];
            pathCompress(par_b);
        }
        return;
    }
};

int main(){
    auto obj = new disjointSetUnion(7);
    obj->unionSet(1,2);
    obj->unionSet(2,3);
    obj->unionSet(4,5);
    obj->unionSet(6,7);
    obj->unionSet(5,6);
    obj->unionSet(3,7);
    return 0;
}