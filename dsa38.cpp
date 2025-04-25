#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int columns = matrix[0].size();
    vector<int> temp(rows, 0);
    vector<vector<int>> vec(columns, temp);
    for(int i =0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            vec[i][j] = matrix[j][i];
        }
        
    }
    for(int i =0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = vec[i][j];
        }
    }
}

int main(){
    vector<vector <int>> vec = {{1,2},{4,5},{7,8}};
    for(auto i1 : vec){
        for(auto i2 : i1){
            cout << i2 << " ";
        }
        cout << endl;
    }
    cout << endl;

    rotate(vec);
    for(auto i1 : vec){
        for(auto i2 : i1){
            cout << i2 << " ";
        }
        cout << endl;
    }
    return 0;
}