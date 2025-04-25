#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans1;
    int max = INT_MIN;
    for(int i = n-1; i >=0; i--){
        if(arr[i] >= max){
            max = arr[i];
            ans1.push_back(arr[i]);
        }
    }
    vector<int> ans2;
    for(auto i = ans1.end()-1; i >= ans1.begin(); i--){
        ans2.push_back(*i);
    }
    return ans2;
}

int main(){
    vector <int> vec = {10, 4, 2, 4, 1};
    vector<int> vec2 = leaders(vec);
    for(auto i : vec2) cout << i <<" ";
    return 0;
}