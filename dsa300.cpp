#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<tuple<int,int>>>adj(n+1);
    for(const auto& vec : edges){
        adj[vec[0]].push_back({vec[1], vec[2]});
        adj[vec[1]].push_back({vec[0], vec[2]});
    }

    vector<int>parent(n+1);
    int tmp =0;
    for(auto& i : parent){
        i = tmp;
        tmp++;
    }

    vector<int>distanceArr(n+1, INT_MAX);
    distanceArr[1]=0;

    //{Path Length, node}
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        if(node.first > distanceArr[node.second]) continue;

        for(const auto& tpl : adj[node.second]){
            auto [n, wght] = tpl;
            int sum = wght+node.first;
            if(sum < distanceArr[n]){
                distanceArr[n] = sum;
                parent[n] = node.second;
                pq.push({sum, n});
            }
        }
    }
    
    if(distanceArr[n] ==INT_MAX)return vector<int>(1,-1);
    stack<int>stk;
    int a=n;
    while(parent[a]!=a){
        stk.push(a);
        a=parent[a];
    }
    stk.push(a);
    vector<int>ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

