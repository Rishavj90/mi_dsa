#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    priority_queue<int>pq;
    for(auto i : arr)pq.push(i);
    int ans = 0;
    int a = pq.size()-k+1;
    while(a--){
        ans = pq.top();
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int>nums = {3,2,1,5,6,4};
    cout << kthSmallest(nums,2);
    return 0;
}