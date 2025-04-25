#include <bits/stdc++.h>
using namespace std;

double findSmallestMaxDist(vector<int> &stations, int k) {
    int n = stations.size();
    vector<int> howManyPlaced(n-1, 0);
    priority_queue<pair<double, int>> pq;
    for(int i = 0; i< n-1; i++){
        double diff = stations[i+1] - stations[i];
        pq.push({diff, i});
    }
    for(int i =1; i<=k; i++){
        auto tp = pq.top(); pq.pop();
        int max_index = tp.second;
        howManyPlaced[max_index]++;
        double in_diff = stations[max_index +1] - stations[max_index];
        double new_diff = (double)in_diff/ (howManyPlaced[max_index] + 1) ;
        pq.push({new_diff, max_index});
    }
    return pq.top().first;
}

int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << findSmallestMaxDist(vec, 9);
    return 0;
}