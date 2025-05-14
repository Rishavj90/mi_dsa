#include <bits/stdc++.h>
using namespace std;

void make_subsequence(vector<vector<int>>&vec,vector<int>& arr, vector<int>&curr, int i,int sum, int k){
    if(vec.size() > 0) return;
    if(sum > k) return;
    if(i == arr.size()){
        if(sum == k){
            vec.push_back(curr);
        }
        return;
    }
    make_subsequence(vec,arr, curr,i+1,sum, k);
    curr.push_back(arr[i]);
    make_subsequence(vec,arr,curr,i+1,sum+arr[i],k);
    curr.pop_back();
}

bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    vector<vector<int>> vec;
    vector<int> curr;
    make_subsequence(vec,arr,curr,0,0,k);
    if(vec.size() != 0){
        return true;
    }
    return false;
}

int main(){
    vector<int> vec= {1,2,3};
    cout << true << " : True, " << false << " : false\n";
    cout << checkSubsequenceSum(vec.size(), vec,4);
    return 0;
}