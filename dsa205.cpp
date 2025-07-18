#include <bits/stdc++.h>
using namespace std;

string isKSortedArray(int arr[], int n, int k) {
    unordered_map<int, int>mpp;
    for(int i = 0; i<n;i++)mpp[arr[i]]=i;
    priority_queue<int, vector<int>, greater<int>>pq;

    vector<int>vec;
    for(int i = 0; i<n;i++)pq.push(arr[i]);
    while(!pq.empty()){
        vec.push_back(pq.top());
        pq.pop();
    }
    for(int i = 0; i < n; i++){
        int b = i > mpp[vec[i]] ?
                (i-mpp[vec[i]]) : (mpp[vec[i]]-i);
        if(b>k)return "No";
    }
    return "Yes";
}
