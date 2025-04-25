#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> &arr){
    int n = arr.size();
    vector<int> hsh(n+1, 0);
    vector<int> ans;
    for(int i = 0; i<n; i++){
        hsh[arr[i]]++;
        if(hsh[arr[i]] == 2) ans.push_back(arr[i]);
    }
    for(int i = 1; i<=n; i++){
        if(hsh[i] == 0) {
            ans.push_back(i);
            break;
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {2,2};
    vector<int> vec2 = findTwoElement(vec);
    for(auto i : vec2){
        cout << i << " ";
    }
    return 0;
}