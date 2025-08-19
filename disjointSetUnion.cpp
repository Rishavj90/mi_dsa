#include <bits/stdc++.h>
using namespace std;

//by size
class disjointSetUnion{
    vector<int>size, parent;
    public:
    disjointSetUnion(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i< parent.size(); i++)parent[i]=i;
    }

    int pathCompress(int a){
        if(a == parent[a])return a;
        return parent[a] = pathCompress(parent[a]);
    }

    void unionSet(int a, int b){
        //check size of their parents
        //update size of their parents 
        //compress their path

        int par_a = pathCompress(a);
        int par_b = pathCompress(b);

        if(par_a == par_b)return;

        if(size[par_a] < size[par_b]){
            parent[par_a] = par_b;
            size[par_b]+= size[par_a];
        }else{
            parent[par_b] = par_a;
            size[par_a]+= size[par_b];  
        }
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