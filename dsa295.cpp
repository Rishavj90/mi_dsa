#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int>visited(n,0);
    for(int i=0; i<n; i++){
        if(visited[i] ==0)visited[i] = dfs(i, visited, graph);
    }

    vector<int>ans;
    for(int i=0; i<n; i++){
        if(visited[i] ==2)ans.push_back(i);
    }
    return ans;
}

//0 : unvisited
//1 : visied,
//-1 : in a loop or unsafe node
//2 : safe node

int dfs(int a, vector<int>& visited, vector<vector<int>>& graph){
    visited[a] = 1;
    for(int i=0; i<graph[a].size(); i++){
        int k = graph[a][i];
        if(visited[k] == 0)visited[k] = dfs(k, visited, graph);
        if(visited[k] == 1 || visited[k] == -1 ){
            visited[a] = -1; 
            return -1;
        }
        
    }
    visited[a] = 2; 
    return 2;
}


