#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<tuple<int,int>>>adj(n+1);
    for(const auto& vec : times){
        adj[vec[0]].push_back({vec[1], vec[2]});
    }

    vector<int>timeArr(n+1, INT_MAX);
    timeArr[0]=0;
    timeArr[k]=0;
    
    //time, node
    priority_queue<tuple<int,int>,
                    vector<tuple<int,int>>,
                    greater<tuple<int,int>>>pq;
    pq.push({0,k});

    while(!pq.empty()){
        auto [timeVal, node] = pq.top();
        pq.pop();
        if(timeVal > timeArr[node])continue;

        for(auto [dstNode, timeWgt] : adj[node]){
            int newVal = timeVal+timeWgt;
            if(newVal < timeArr[dstNode]){
                timeArr[dstNode]=newVal;
                pq.push({newVal, dstNode});
            }
        }
    }
    int MaxTime= INT_MIN;
    for(const auto &i : timeArr){
        if(i == INT_MAX)return -1;
        MaxTime=(i>MaxTime)?i : MaxTime;
    }
    return MaxTime;

}

