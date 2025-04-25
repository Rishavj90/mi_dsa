#include <bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int> &arr, int k) {
    int n = arr.size();
    unordered_map<int, int> preXor;
    preXor[0] = 1;
    long count = 0, j = 0;
    for(int i = 0; i < n; i++){
        j = j^arr[i];
        count += preXor[j^k];
        preXor[j]++;
    }
    return count;
}

int main(){
    vector<int> vec = {1,1,1,1};
    cout << subarrayXor(vec, 0);
    return 0;
}