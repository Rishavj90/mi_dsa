#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<tuple<int,long long>>>adj(n);
    for(const auto& vec : roads){
        adj[vec[0]].push_back({vec[1], vec[2]});
        adj[vec[1]].push_back({vec[0], vec[2]});
    }

    long long mod=1e9+7;

    vector<long long>timeArr(n, LONG_MAX);
    timeArr[0]=0;
    vector<long long>waysArr(n, 0);
    waysArr[0]=1;

    //time, node
    priority_queue<tuple<long long,long long>,
                    vector<tuple<long long,long long>>,
                    greater<tuple<long long,long long>>>pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto [timeVal, node] = pq.top();
        pq.pop();

        if(timeVal > timeArr[node])continue;

        for(auto [toNode, timeWgt] : adj[node]){
            long long newTime = timeVal+timeWgt;

            if(newTime < timeArr[toNode]){
                waysArr[toNode]=waysArr[node];
                timeArr[toNode]=newTime;
                pq.push({newTime, toNode});
            }else if(newTime == timeArr[toNode]){
                waysArr[toNode] = (waysArr[toNode] + waysArr[node]) % mod;
            }
            
        }
    }
    return waysArr[n-1];
}

