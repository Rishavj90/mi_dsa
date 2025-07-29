#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>mpp;
    for(auto i : nums)mpp[i]++;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(auto i : mpp){
        pq.push({i.second,i.first});
        if(pq.size()>k)pq.pop();
    }
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}