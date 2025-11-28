#include <bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int>visited(V,0);
    vector<vector<int>>adjList(V);
    for(int i = 0; i<edges.size(); i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i = 0; i<V; i++){
        if(visited[i] == 0){
            if(bfs(i, visited, adjList))return true;
        }
    }
    return false;
}

bool bfs(int a, vector<int>&visited, vector<vector<int>>&adjList){
    queue<pair<int,int>>q;
    //{node, parent}
    q.push({a, -1});
    visited[a] = 1;
    while(!q.empty()){
        int num = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int i = 0; i< adjList[num].size(); i++){
            if(visited[adjList[num][i]] == 0){
                q.push({adjList[num][i], num});
                visited[adjList[num][i]] = 1;
            }
            else if(visited[adjList[num][i]] == 1 && adjList[num][i] != parent)return true;
        }
    }
    return false;
}


