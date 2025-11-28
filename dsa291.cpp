#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adjList(numCourses);
    vector<int>inDegree(numCourses, 0);

    for(int i=0; i<prerequisites.size(); i++){
        int course=prerequisites[i][0], preReq=prerequisites[i][1];
        adjList[preReq].push_back(course);
        inDegree[course]++;
    }

    vector<int>ans;
    bfs(numCourses, adjList, inDegree, ans);
    return ans;

}

void bfs(int numCourses, vector<vector<int>>&adjList, vector<int>&inDegree, vector<int>&ans){
    queue<int>q;
    for(int i=0; i<numCourses; i++){
        if(inDegree[i]==0)q.push(i);
    }

    while(!q.empty()){
        int a=q.front();
        q.pop();
        ans.push_back(a);

        for(int i=0; i<adjList[a].size(); i++){
            int num=adjList[a][i];
            inDegree[num]--;
            if(inDegree[num]==0)q.push(num);
        }
    }

    if(ans.size() < numCourses)ans.clear();
}


