#include <bits/stdc++.h>
using namespace std;

int findCircleNum(vector<vector<int>>&isConnected){
    int n = isConnected.size();
    vector<int>visited(n);
    int provinces = 0;
    for(int i = 0; i< n; i++){
        if(visited[i] == 0){
            provinces++;
            bfs(i, isConnected, visited);
        }
    }
    return provinces;
}

void bfs(int a, vector<vector<int>>&isConnected, vector<int>&visited){
    queue<int>q;
    q.push(a);
    visited[a] = 1;

    while(!q.empty()){
        int num = q.front();
        q.pop();
        int n = isConnected[num].size();
        for(int i = 0; i< n; i++){
            if(isConnected[num][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}


