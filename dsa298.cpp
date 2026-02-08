#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<tuple<int,int>>>adj(V);
    vector<int>Indegree(V, 0);
    for(const auto& vec : edges){
        adj[vec[0]].push_back({vec[1], vec[2]});
        Indegree[vec[1]]++;
    }

    queue<int>q;
    for(int i = 0; i < V; i++) {
        if(Indegree[i] == 0) q.push(i);
    }

    vector<int>topSort;
    while(!q.empty()){
        int node = q.front();
        topSort.push_back(node);
        q.pop();

        for(const auto& vec : adj[node]){
            auto [des, length] = vec;
            Indegree[des]--;
            if(Indegree[des] == 0)q.push(des);
        }
        
    }
    vector<int>ans(V, INT_MAX);
    ans[0]=0;
    for(int i=0; i<V; i++){
        int a=topSort[i];
        if(ans[a] != INT_MAX) {
            for(const auto& vec : adj[a]){
                auto [des, len] = vec;
                ans[des] = min(ans[des], ans[a]+len);
            }
        }
    }
    for(int i=0; i<V; i++){
        if(ans[i] == INT_MAX)ans[i]=-1;
    }
    return ans;
}




