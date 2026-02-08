#include <bits/stdc++.h>
using namespace std;

/*
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<tuple<int,int>>>adj(n);
    for(const auto& vec : edges){
        adj[vec[0]].push_back({vec[1], vec[2]});
        adj[vec[1]].push_back({vec[0], vec[2]});
    }
    vector<int>cityNums(n,0);
    for(int i=0; i<n; i++){
        dijkstra(adj, distanceThreshold, cityNums,i,n);
    }
    int ans_index=INT_MAX, ans_val=INT_MAX;
    for(int i=0; i<n; i++){
        if(cityNums[i]<ans_val){
            ans_val = cityNums[i];
            ans_index = i;
        }
        if(cityNums[i]==ans_val){
            ans_index=max(i, ans_index);
        }
    }
    return ans_index;
}

void dijkstra(vector<vector<tuple<int,int>>>& adj, int distanceThreshold, vector<int>& cityNums, int a, int n){
    vector<int>distanceArr(n, INT_MAX);
    distanceArr[a]=0;

    //{Path Length, node}
    priority_queue<pair<int, int>, 
                    vector<pair<int,int>>, 
                    greater<pair<int,int>>>pq;
    pq.push({0,a});
    while(!pq.empty()){
        auto [dist, node] = pq.top();
        pq.pop();
        if(dist > distanceArr[node]) continue;

        for(auto [newNode, wgt] : adj[node]){
            int newDist = wgt+dist;
            if(newDist < distanceArr[newNode]){
                distanceArr[newNode] = newDist;
                pq.push({newDist, newNode});
            }
        }
    }
    for(const auto &i : distanceArr){
        if(i<=distanceThreshold)cityNums[a]++;
    }
}
*/


int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>>dist(n,vector<int>(n, INT_MAX));
    for(const auto &vec: edges){
        int Node1=vec[0], Node2=vec[1], wgt=vec[2];
        dist[Node1][Node2]=wgt;
        dist[Node2][Node1]=wgt;
    }
    for(int i=0; i<n; i++) dist[i][i] = 0;

    vector<int>cityNums(n,0);
    floydWarshall(dist, distanceThreshold, cityNums);
    
    int ans_index=INT_MAX, ans_val=INT_MAX;
    for(int i=0; i<n; i++){
        if(cityNums[i]<ans_val){
            ans_val = cityNums[i];
            ans_index = i;
        }
        if(cityNums[i]==ans_val){
            ans_index=max(i, ans_index);
        }
    }
    return ans_index;

}

void floydWarshall(vector<vector<int>> &dist, int distanceThreshold, vector<int>& cityNums) {
    int n=dist.size();
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k] !=INT_MAX && dist[k][j] !=INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(const auto &val : dist[i]){
            if(val>0 && val<=distanceThreshold)cityNums[i]++;
            //val>0 to prevent self counting
        }
    }
}



