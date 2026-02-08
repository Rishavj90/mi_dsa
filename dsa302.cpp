#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int r=heights.size(), c=heights[0].size();
    vector<vector<int>>effort(r, vector<int>(c, INT_MAX));
    effort[0][0]=0;

    vector<int>moveX={1,0,-1,0};
    vector<int>moveY={0,1,0,-1};

    //{effort, x, y}
    priority_queue<tuple<int, int, int>, 
                    vector<tuple<int,int,int>>, 
                    greater<tuple<int, int, int>>>pq;
    pq.push({0,0,0});
    

    while(!pq.empty()){
        auto [nodeEffort, nodeX, nodeY] = pq.top();
        pq.pop();

        //in pq, the topmost element is smallest, which is poped. so for lesser "max diff" to exist, it must've been long popped.
        if(nodeX == r-1 && nodeY == c-1)return nodeEffort;

        if(nodeEffort > effort[nodeX][nodeY]) continue;

        for(int i=0; i<4; i++){
            int newX=nodeX+moveX[i], newY=nodeY+moveY[i];
            if(
                newX >=0 && newX<r &&
                newY >=0 && newY<c
            ){
                int diff = abs(heights[newX][newY]-heights[nodeX][nodeY]);
                int newEffort = max(nodeEffort, diff);

                if(newEffort < effort[newX][newY]){
                    effort[newX][newY] = newEffort;
                    pq.push({newEffort, newX, newY});
                }
            }
        }
    }

    return effort[r-1][c-1];
}


