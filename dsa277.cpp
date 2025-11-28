#include <bits/stdc++.h>
using namespace std;

/*
1. Build adjacency list from edges
2. Create visited array
3. For each vertex:
   - If not visited:
     - Start new component
     - DFS/BFS to find all vertices in this component
     - Add component to result
4. Return result

*/

vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    vector<vector<int>>adjList(V);
    for(auto edge : edges){
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    vector<int>visited(V,0);
    vector<vector<int>>ans;
    for(int i = 0; i <V; ++i){
        if(visited[i] == 0){
            vector<int> connected = bfs(i,adjList, visited);
            ans.push_back(connected);
        }
    }
    return ans;
}

vector<int> bfs(int i, vector<vector<int>>&adjList, vector<int>&visited){
    vector<int> ans;
    queue<int>q;
    q.push(i);
    visited[i] = 1;
    while(!q.empty()){
        int num = q.front();
        ans.push_back(num);
        q.pop();
        for(int j = 0; j < adjList[num].size(); ++j){
            if(visited[adjList[num][j]] == 0){
                q.push(adjList[num][j]);
                visited[adjList[num][j]] = 1;
            }
        }
    }
    return ans;
}


