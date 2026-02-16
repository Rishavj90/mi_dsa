#include <bits/stdc++.h>
using namespace std;

class Solution {
vector<int>discoveryTime, lowTime;
vector<bool>visited, ans;
int timeVal=0;

void dfs(int node, int parent, vector<int> adj[]){
    visited[node] = true;
    discoveryTime[node]=timeVal;
    lowTime[node]=timeVal;
    timeVal++;

    int children=0;

    for(auto &nextNode : adj[node]){
        if(nextNode == parent) continue;

        if(!visited[nextNode]){
            children++;
            dfs(nextNode, node, adj);

            //fix low time
            lowTime[node] = min(lowTime[nextNode], lowTime[node]);

            //can't reach anything before parent, when there is something before parent
            if(parent !=-1 && lowTime[nextNode] >= discoveryTime[node])ans[node]=true;

        }else{
            //found the loop
            lowTime[node] = min(discoveryTime[nextNode], lowTime[node]);
        }
        
    }

    //there is nothing before parent and there are children >= 2
    if(parent==-1 && children >1)ans[node]=true;

}

public:
vector<int> articulationPoints(int V, vector<int> adj[]) {
    discoveryTime.resize(V, 0);
    lowTime.resize(V, 0);
    visited.resize(V, false);
    ans.resize(V, false);

    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs(i, -1, adj);
        }
    }

    vector<int>tmp;
    for(int i=0; i<V; i++){
        if(ans[i])tmp.push_back(i);
    }
    if(tmp.empty())return {-1};
    return tmp;
}


};



