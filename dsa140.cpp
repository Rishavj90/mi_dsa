#include <bits/stdc++.h>
using namespace std;

bool diff_color(int node,vector<int> &node_color,vector<vector<int>> &edges){
    for(auto i : edges){
        if(i[0] == node && i[1] != node && node_color[i[0]] == node_color[i[1]])return false;
    }
    return true;
}

bool test_color(int node,vector<int> &node_color,int v,vector<vector<int>> &edges, int m){
    if(node == v)return true;
    for(int i = 1; i <= m; ++i){
        node_color[node] = i;
        if(diff_color(node, node_color,edges) && test_color(node+1,node_color,v,edges,m))return true;
        node_color[node] = -1;
    }
    return false;
}

bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    vector<int> node_color(v,-1);
    return test_color(0,node_color,v,edges,m);
}