#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
    vector<vector<int>>adj(V);
    for(const auto &vec : edges){
        adj[vec[0]].push_back(vec[1]);
        adj[vec[1]].push_back(vec[0]);
    }

    vector<int> ans(V, -1);
    vector<int>visited(V, 0);
    queue<int>q;
    q.push(src);
    visited[src]=1;

    int pathLen = 0;
    while(!q.empty()){
        int n=q.size();
        while(n--){
            int a=q.front();
            q.pop();
            ans[a] = pathLen;

            for(const auto& i : adj[a]){
                if(visited[i]==0){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        pathLen++;
    }
    return ans;
}

