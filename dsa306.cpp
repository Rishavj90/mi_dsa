#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    long mod = 1e5;
    vector<bool> visited(mod, false);
    
    queue<pair<int,int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()){
        auto [num, steps] = q.front();
        q.pop();

        if(num == end) return steps;

        for(const auto &i : arr){
            int newNum = (long(num) * long(i)) % mod;
            
            if(!visited[newNum]){
                visited[newNum] = true;
                q.push({newNum, steps + 1});
            }
        }
    }
    return -1;
}

