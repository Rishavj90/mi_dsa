#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int r = 0, c = matrix[0].size()-1;
    while(r < matrix.size() && c >= 0){
        if(matrix[r][c] < target){
            r++;
        }else if(matrix[r][c] > target){
            c--;
        }else{
            return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1, 3},{2,5}};
    cout << "True : " << true << ", False : " << false << endl;
    cout << searchMatrix(matrix, 6);
    return 0;
}