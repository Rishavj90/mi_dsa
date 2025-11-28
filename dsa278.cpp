#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int v, vector<vector<int>>&edge){
    vector<vector<int>>adjList(v);
    vector<bool>visited(v, false);

    //make adjacency list
    for(auto vec : edge){
        adjList[vec[0]].push_back(vec[1]);
        adjList[vec[1]].push_back(vec[0]);
    }

    vector<int> traversal;
    queue<int>q;
    for(int i =0; i< v; i++){
        if(!visited[i]){
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int num = q.front();
                q.pop();
                traversal.push_back(num);
                for(int k = 0; k< adjList[num].size(); ++k){
                    int node = adjList[num][k];
                    if(!visited[node]){
                        q.push(node);
                        visited[node] = true;
                    }
                }
            }
        }
    }
    

    return traversal;
}

vector<int> dfs(int v, vector<vector<int>>&edge){
    vector<vector<int>>adjList(v);
    vector<bool>visited(v, false);

    //make adjacency list
    for(auto vec : edge){
        adjList[vec[0]].push_back(vec[1]);
        adjList[vec[1]].push_back(vec[0]);
    }

    vector<int> traversal;
    stack<int>stk;

    for(int i = 0; i< v; i++){
        if(!visited[i]){
            stk.push(i);
            visited[i] = true;
            
            while(!stk.empty()){
                int num = stk.top();
                traversal.push_back(num);
                stk.pop();
                int n = adjList[num].size();
                for(int k = n-1; k>=0; --k){
                    int node = adjList[num][k];
                    if(!visited[node]){
                        stk.push(node);
                        visited[node] = true;
                    }
                }
            }

        }
    }
    
    return traversal;
}

vector<int> dfs_recursive(int v, vector<vector<int>>&edge){
    vector<vector<int>>adjList(v);
    vector<bool>visited(v, false);

    //make adjacency list
    for(auto vec : edge){
        adjList[vec[0]].push_back(vec[1]);
        adjList[vec[1]].push_back(vec[0]);
    }
    vector<int> traversal;
    for(int i = 0; i< v; i++){
        if(!visited[i]){
            helper(i, adjList, visited, traversal);
        }
    }
    return traversal;
} 

void helper(int a, vector<vector<int>>&adjList, vector<bool>&visited, vector<int>&traversal){
    visited[a] = true;
    traversal.push_back(a);
    for(auto itr : adjList[a]){
        if(!visited[itr]){
            helper(itr,adjList,visited,traversal);
        }
    }
}
