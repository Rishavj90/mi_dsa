#include <bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    for(int i = 0; i < arr.size(); i++)pq.push({arr[i],i});

    int prev = INT_MAX;
    int rank = 0;
    vector<int>ans = arr;
    while(!pq.empty()){
        if(pq.top().first != prev){
            rank++;
        }
        ans[pq.top().second] = rank;
        prev = pq.top().first;
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int>vec= {37,12,28,9,100,56,80,5,12};
    vector<int>ans= arrayRankTransform(vec);
    for(auto i : ans)cout << i << " ";
    return 0; 
}