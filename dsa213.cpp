#include <bits/stdc++.h>
using namespace std;

vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    priority_queue<pair<int,pair<int,int>>>pq;
    unordered_map<int,bool>visited;
    pq.push({a[0]+b[0],{0,0}});
    visited[0]=true; //{n*i+j}

    int n = a.size();
    vector<int>ans;
    while(k--){
        auto top = pq.top();
        pq.pop();
        ans.push_back(top.first);
        int i = top.second.first;
        int j = top.second.second;

        if(i+1<a.size() && visited[n*(i+1)+j]!=true){
            pq.push({a[i+1]+b[j],{i+1,j}});
            visited[n*(i+1)+j]=true;
        }

        if(j+1<a.size() && visited[n*i+(j+1)]!=true){
            pq.push({a[i]+b[j+1],{i,j+1}});
            visited[n*i+(j+1)]=true;
        }
    }
    return ans;
}

int main(){
    vector<int>a = {4, 1, 6, 1, 10};
    vector<int>b = {6, 5, 2, 7, 8};
    vector<int>ans = topKSumPairs(a, b,4);
    for(auto i : ans)cout << i << " ";
}