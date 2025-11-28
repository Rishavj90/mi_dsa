#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int m=graph.size();
    vector<int>visited(m, -1);

    for(int i=0; i<m; i++){
        if(visited[i] == -1){
            bool flag = bfs(i, visited, graph);
            if(!flag)return false;
        }
    }
    return true;
    
}

bool bfs(int i, vector<int>& visited, vector<vector<int>>& graph){
    visited[i] = 0;
    queue<int>q;
    q.push(i);

    while(!q.empty()){
        int ind = q.front(), color=visited[ind];
        q.pop();
        if(color == 0)color++;
        else color = 0;

        for(int a=0; a<graph[ind].size(); a++){
            int num = graph[ind][a];
            if(visited[num] == -1){
                q.push(num);
                visited[num] = color;
            }else if(visited[num] != color)return false;
        }
    }
    return true;
}


