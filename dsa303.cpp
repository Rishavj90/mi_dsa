#include <bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<vector<tuple<int,int>>>adj(n);
    for(const auto& vec : flights){
        adj[vec[0]].push_back({vec[1], vec[2]});
    }

    vector<vector<int>>trackCity(n,vector<int>(K+2, INT_MAX));
    
    //stops,cost,city
    queue<tuple<int,int,int>>q;
    
    q.push({0,0,src});
    trackCity[src][0]=0;

    while(!q.empty()){
        auto [stops,cost,from] = q.front();
        q.pop();

        for(auto [toCity, val] : adj[from]){
            int newCost = cost+val, newStop = stops+1;
            if(newStop<(K+2) && newCost< trackCity[toCity][newStop]){
                q.push({newStop, newCost, toCity});
                trackCity[toCity][newStop]=newCost;
            }

        }
    }

    int MinCost = INT_MAX;
    for(auto i : trackCity[dst]){
        if(i<MinCost)MinCost = i;
    }
    if(MinCost!=INT_MAX)return MinCost;
    return -1;
}

