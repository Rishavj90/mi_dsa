#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(auto i : nums)pq.push(i);
        while(pq.size()>k)pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>_k)pq.pop();
        int ans = pq.top();
        return ans;
    }
};

int main(){
    vector<int>vec= {-2};
    KthLargest* obj = new KthLargest(1,vec);
    cout << obj->add(-3) << " ";
    cout << obj->add(-2) << " ";
    cout << obj->add(-4) << " ";
    cout << obj->add(0) << " ";
    cout << obj->add(4) << " ";
    
    return 0;
}