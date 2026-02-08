#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adj(numCourses);
    vector<int>Indegree(numCourses, 0);
    for(auto itr : prerequisites){
        adj[itr[1]].push_back(itr[0]);
        Indegree[itr[0]]++;
    }
    
    queue<int>q;
    vector<int>ans;
    for(int i=0; i<numCourses; ++i){
        if(Indegree[i] ==0)q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0; i<adj[node].size(); i++){
            int a = adj[node][i];
            Indegree[a]--;
            if(Indegree[a] == 0)q.push(a);
        }
    }
    if(ans.size() != numCourses)return false;
    return true;
}


