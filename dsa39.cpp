#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    //Transposing the matrix;
    int n = matrix.size();
    for(int i =0; i < n; i++){
        for(int j = i+1;j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j =0; j < n/2;j++){
            swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }
    return;
}

int main(){
    vector<vector <int>> vec = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(vec);
    for(auto i1 : vec){
        for(auto i2 : i1){
            cout << i2 << " ";
        }
        cout << endl;
    }
    return 0;
}