#include <bits/stdc++.h>
using namespace std;

class kosarajuAlgo {
vector<vector<int>>Adj, transposeAdj;
stack<int>stk;
vector<bool>visited;

void dfs1(int node){
    visited[node]=true;
    for(auto &i : Adj[node]){
        if(!visited[i])dfs1(i);
    }
    stk.push(node);
}

void makeTransposeGraph(vector<vector<int>>&graph){
    for(auto &vec : graph){
        transposeAdj[vec[1]].push_back(vec[0]);
    }
}

void dfs2(int node, vector<int>&SCC){
    visited[node]=true;
    SCC.push_back(node);
    for(auto &i : transposeAdj[node]){
        if(!visited[i])dfs2(i, SCC);
    }
}

public:
vector<vector<int>> SCCList(int V, vector<vector<int>>&graph) {
    Adj.assign(V, {});  
    transposeAdj.assign(V, {});
    visited.assign(V, false);
    while(!stk.empty())stk.pop();  //ensures clean-empty stack, everytime SCCList is called 

    for(auto &vec : graph){
        Adj[vec[0]].push_back(vec[1]);
    }

    for(int i=0; i<V; i++){
        if(!visited[i])dfs1(i);
    }
    visited.assign(V, false);

    makeTransposeGraph(graph);

    vector<vector<int>>ans;
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        vector<int>SCC;
        if(!visited[node]){
            dfs2(node, SCC);
            ans.push_back(SCC);
        }
    }

    return ans;
}


};

