#include <bits/stdc++.h>
using namespace std;

void make_set(vector<vector<int>>&vec, vector<int>&curr, vector<int>&temp, int i, int target){
    if(target==0){
        vec.push_back(curr);
        return;
    }
    if(i == temp.size()||temp[i]>target)return;
    
    curr.push_back(temp[i]);
    make_set(vec,curr,temp,i+1,target-temp[i]);
    curr.pop_back();
    while(i+1 != temp.size() && temp[i]==temp[i+1])i++;
    make_set(vec,curr,temp,i+1,target);
   
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> vec;
    vector<int> curr;
    vector<int> temp = candidates;
    sort(temp.begin(), temp.end());
    make_set(vec,curr,temp,0,target);
    return vec;
}
int main(){
    vector<int> vec = {2,2,2};
    vector<vector<int>> arr = combinationSum2(vec,2);
    for(auto i : arr){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}