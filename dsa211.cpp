#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int>& arr) {
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto i : arr)pq.push(i);
    int cost = 0;
    while(!pq.empty()){
        int a = pq.top();
        pq.pop();
        int b;
        if(!pq.empty()){
            b = pq.top();
            pq.pop();
            int sum = a+b;
            cost+=sum;
            pq.push(sum);
        }
        else return cost;
    }
    return cost;
}

int main(){
    vector<int>arr= {4, 2, 7, 6, 9};
    cout << minCost(arr);
    return 0;
}