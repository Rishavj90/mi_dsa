#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    int newMax= 1e8;
    vector<int>ans(V,newMax);
    ans[src]=0;
    int n=V-1;
    while(n--){
        for(const auto &vec : edges){
            int fromNode = vec[0], toNode = vec[1], wgt = vec[2];

            if(ans[fromNode] != newMax && (ans[fromNode]+wgt) < ans[toNode]){
                ans[toNode]=ans[fromNode]+wgt;
            }
        }
    }
    
    for(const auto &vec : edges){
        int fromNode = vec[0], toNode = vec[1], wgt = vec[2];
        int newVal= ans[fromNode]+wgt;
        if(ans[fromNode] != newMax && newVal < ans[toNode]){
            return {-1};
        }
    }

    return ans;
}

