#include <bits/stdc++.h>
using namespace std;

//Dijkstra's algo
/* with PQ 
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<tuple<int,int>>>adj(V);
    for(const auto& vec : edges){
        adj[vec[0]].push_back({vec[1], vec[2]});
    }

    vector<int>ans(V, INT_MAX);
    ans[0]=0;
    //{Path Length, node}
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        if(node.first > ans[node.second]) continue;

        for(const auto& tpl : adj[node.second]){
            auto [n, wght] = tpl;
            int sum = wght+node.first;
            if(sum < ans[n]){
                ans[n] = sum;
                pq.push({sum, n});
            }
        }
    }
    for(auto& i : ans){
        if(i == INT_MAX)i=-1;
    }
    return ans;
}
*/

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<tuple<int,int>>>adj(V);
    for(const auto& vec : edges){
        adj[vec[0]].push_back({vec[1], vec[2]});
    }

    vector<int>ans(V, INT_MAX);
    ans[0]=0;
    //{Path Length, node}
    set<pair<int,int>>st;
    st.insert({0,0});
    while(!st.empty()){
        auto [dist, node] = *st.begin();
        st.erase({dist, node});
        
        for(auto &tpl : adj[node]){
            auto [des, wgt] = tpl;
            int newDist= dist+wgt;
            if(newDist < ans[des]){
                if(ans[des]!=INT_MAX)st.erase({ans[des], des});
                ans[des] = newDist;
                st.insert({newDist, des});
            }
        }
    }
    for(auto& i : ans){
        if(i == INT_MAX)i=-1;
    }
    return ans;
}


