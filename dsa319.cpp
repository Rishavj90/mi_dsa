#include <bits/stdc++.h>
using namespace std;

class Solution {
vector<bool>visited;
vector<int>discoveryTime, lowTime;
vector<vector<int>> adjList, ans;
int timeVal=0;

void dfs(int node, int parent){
    visited[node]=true;
    discoveryTime[node]=timeVal;
    lowTime[node] = timeVal;
    timeVal++;
    
    for(auto &nextNode : adjList[node]){
        if(nextNode != parent){
            if(!visited[nextNode]){
                dfs(nextNode, node);
                
                //update low time of parent nodes
                lowTime[node] = min(lowTime[node], lowTime[nextNode]);

                //found a bridge
                if(lowTime[nextNode] > discoveryTime[node])ans.push_back({node, nextNode});
                
            }else{
                //already visited node found
                lowTime[node] = min(lowTime[node], discoveryTime[nextNode]); 
            }
        }
    }
}


public:
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    visited.resize(n, false);
    discoveryTime.resize(n, 0);
    lowTime.resize(n, 0);
    adjList.resize(n);

    for(auto &vec : connections){
        adjList[vec[0]].push_back(vec[1]);
        adjList[vec[1]].push_back(vec[0]);
    }

    for(int i=0; i<n; i++){
        if(!visited[i])dfs(i,-1);
    }

    return ans;
}
};


