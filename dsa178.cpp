#include <bits/stdc++.h>
using namespace std;

vector<int>nextGreater_left(vector<int>&arr){
    vector<int>ngL(arr.size(), -1);
    stack<int>stk;
    for(int i = 0; i < arr.size(); i++){
        while(!stk.empty() && arr[stk.top()] >= arr[i])stk.pop();
        ngL[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    return ngL;
}
vector<int>nextGreater_right(vector<int>&arr){
    vector<int>ngR(arr.size(), arr.size());
    stack<int>stk;
    for(int i = arr.size() -1; i >=0 ; i--){
        while(!stk.empty() && arr[stk.top()] > arr[i])stk.pop();
        ngR[i] = stk.empty() ? arr.size() : stk.top();
        stk.push(i);
    }
    return ngR;
}

int sumSubarrayMins(vector<int>& arr) {
    vector<int>ngL = nextGreater_left(arr);
    vector<int>ngR = nextGreater_right(arr);
    long long ans = 0, lim = 1e9+7;
    for(int i = 0; i < arr.size(); i++){
        long long l = i - ngL[i], r = ngR[i] - i;
        long long res = (l*r*arr[i])%lim;
        ans += res;
    }
    return ans%lim;
}

int main(){
    vector<int>arr = {3,1,2,4};
    cout << sumSubarrayMins(arr);
    return 0;
}