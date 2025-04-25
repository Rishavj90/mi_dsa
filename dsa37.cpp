#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    vector<int>mpp;
    int rows = matrix.size();
    int columns = matrix[0].size();
    for(int i =0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(matrix[i][j] == 0){
                mpp.push_back(i);
                mpp.push_back(j);
            }
        }
    }
    for(int k = 0; k < mpp.size(); k+=2){
        int new_row = mpp[k];
        int new_column = mpp[k+1];
        //Updating the row
        for(int a = 0; a < columns; a++){
            matrix[new_row][a] = 0;
        }
        //updating the column
        for(int b = 0; b < rows; b++){
            matrix[b][new_column] = 0;
        }
    }
    return;
}

int main(){
    vector<vector <int>> vec = {{1,1,1},{1,0,1},{1,1,1}};
    for(auto i1 : vec){
        for(auto i2 : i1){
            cout << i2 << " ";
        }
        cout << endl;
    }
    cout << endl;

    setZeroes(vec);
    for(auto i1 : vec){
        for(auto i2 : i1){
            cout << i2 << " ";
        }
        cout << endl;
    }
    return 0;
}