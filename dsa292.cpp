#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]){
    stack<int>stk;
    vector<int>visited(V, 0);
    for(int i=0; i<V; i++){
        if(visited[i] == 0){
            dfs(i, adj, stk, visited);
        }
    }
    vector<int>ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;

}

void dfs(int a, vector<int> adj[], stack<int>&stk, vector<int>&visited){
    visited[a] = 1;
    for(int i=0; i<adj[a].size(); i++){
        if(visited[adj[a][i]] == 0){
            dfs(adj[a][i], adj, stk, visited);
        }
    }
    stk.push(a);
    /*
    stk.push(a) comes after visiting child elements bcz say if 'b' needs to be done before doing 'a' and 'c' then a and c should be pushed in stack first and then b, such that upon clearing elements from stack in vector we get the reversed sequence : b, a, c
    */
   
}




