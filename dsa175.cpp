#include <bits/stdc++.h>
using namespace std;

void nextSmaller(vector<int>& arr) {
    stack<int>stk;
    vector<int>tmp(arr.size(), 0);
    for(int i = arr.size()-1; i >= 0; --i){
        while(!stk.empty() && stk.top()>= arr[i])stk.pop();
        tmp[i] = stk.empty()? -1 : stk.top();
        stk.push(arr[i]);
    }
    arr = tmp;
    return;
}

int main(){
    vector<int>vec = {5,9,6,3,20};
    nextSmaller(vec);
    for(auto i : vec) cout << i << " ";
    return 0;
}
