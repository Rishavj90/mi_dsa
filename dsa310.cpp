#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<int>visited(V,0);

    //weight, node
    priority_queue<tuple<int,int>,
                    vector<tuple<int,int>>,
                    greater<tuple<int,int>>>pq;
    
    pq.push({0,0});
    int ans=0;

    while(!pq.empty()){
        auto [wgt, node] = pq.top();
        pq.pop();
        if(visited[node]==1)continue;
        visited[node]=1;
        ans+=wgt;

        for(const auto &vec : adj[node]){
            int newNode=vec[0], newWgt=vec[1];

            if(visited[newNode]==0){
                pq.push({newWgt, newNode});
            }
        }
    }
    
    return ans;
    
}

