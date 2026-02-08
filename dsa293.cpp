#include <bits/stdc++.h>
using namespace std;

//for valid DAGs only0
vector<int> topoSort(int V, vector<int> adj[]){
    vector<int>Indegree(V, 0);
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            int k = adj[i][j];
            Indegree[k]++;
        }
    }

    queue<int>q;
    vector<int>ans;
    for(int i=0; i<V; i++){
        if(Indegree[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0; i<adj[node].size(); i++){
            int a = adj[node][i];
            Indegree[a]--;
            if(Indegree[a] == 0)q.push(a);
        }
        
    }
    return ans;

}


