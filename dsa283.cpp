#include <bits/stdc++.h>
using namespace std;


bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int>visited(V, 0);
    vector<vector<int>>adjList(V);

    for(auto edg : edges){
        adjList[edg[0]].push_back(edg[1]);
        adjList[edg[1]].push_back(edg[0]);
    }

    for(int i = 0; i<V; i++){
        if(visited[i] == 0){
            if(dfs(i, -1, visited, adjList))return true;
        }
    }
    return false;
}

bool dfs(int num, int parent, vector<int>&visited, vector<vector<int>>&adjList){
    visited[num] = 1;
    for(int i = 0; i< adjList[num].size(); i++){
        if(visited[adjList[num][i]] == 0){
            if(dfs(adjList[num][i], num, visited, adjList))return true;
        }
        else if(visited[adjList[num][i]] == 1 && adjList[num][i] != parent)return true;
        
    }
    return false;
}



