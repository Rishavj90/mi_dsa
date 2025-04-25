#include <bits/stdc++.h>
using namespace std;

//Pascal's Triangle
vector<vector<int>> generate(int numRows){
    int n = numRows;
    vector<vector<int>> vec;
    for(int i = 0; i < n; i++){
        vector<int> temp(i+1);
        vec.push_back(temp);
        vec[i][0] = 1;
        vec[i][i] = 1;
        for(int j = 1; j < i; j++){
            vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
        }
    }
    return vec;
}

int main(){
    int k = 5;
    vector<vector<int>> vec = generate(k);
    for(auto i : vec){
        for(int num = 1;num < k; num++){
            cout << " ";
        }
        for(auto j : i){
            cout << j << " ";
        }
        cout <<endl;
        k--;
    }
}