#include <bits/stdc++.h>
using namespace std;

void make_combination(vector<vector<int>>&vec,vector<int>&curr, vector<int>& candidates, int i, int sum, int target){
    if(i == candidates.size() || sum > target)return;
    if(target == sum){
        vec.push_back(curr);
        return;
    }
    curr.push_back(candidates[i]);
    make_combination(vec,curr,candidates,i,sum+candidates[i],target);
    curr.pop_back();
    make_combination(vec,curr,candidates,i+1,sum, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> vec;
    vector<int> curr;
    make_combination(vec,curr,candidates,0,0,target);
    return vec;
}

int main(){
    vector<int> arr = {8,4,3,7};
    vector<vector<int>> vec = combinationSum(arr,11);
    for(auto i : vec){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
