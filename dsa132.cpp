#include <bits/stdc++.h>
using namespace std;

void make_vec(vector<vector<int>>&vec,vector<int>&curr,int num,int k, int n){
    //k numbers //sum n
    if(k==0){
        if(n==0)vec.push_back(curr);
        return;
    }
    if(num>9)return;
    curr.push_back(num);
    make_vec(vec,curr,num+1,k-1,n-num);
    curr.pop_back();
    make_vec(vec,curr,num+1,k,n);
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>>vec;
    vector<int>curr;
    make_vec(vec,curr,1,k,n);
    return vec;
}
int main(){
    vector<vector<int>>arr = combinationSum3(9,45);
    for(auto vec : arr){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}