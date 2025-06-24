#include <bits/stdc++.h>
using namespace std;

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
    vector<int>ans(n,0);
    stack<int>stk;
    for(int i = n-1; i >= 0; i--){
        stack<int>temp;
        while(!stk.empty() && arr[i] >= stk.top()){
            temp.push(stk.top());
            stk.pop();
        }
        ans[i] = stk.size();
        stk.push(arr[i]);
        while(!temp.empty()){
            stk.push(temp.top());
            temp.pop();
        }
    }
    vector<int>index_ans(queries,0);
    for(int i = 0; i < indices.size(); ++i){
        index_ans[i] = ans[indices[i]];
    }
    return index_ans;
}

int main(){
    vector<int>vec = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int>indices = {0,5};
    vector<int>vec3 = count_NGE(vec.size(), vec, indices.size(), indices);
    for(auto i : vec3)cout << i << " ";
    return 0;
}