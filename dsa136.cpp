#include <bits/stdc++.h>
using namespace std;

bool safe_pos(int r,int c,vector<string>&grid){
    int n = grid.size();
    //check linear left
    for(int i = c;i>=0;--i){
        if(grid[r][i]=='Q')return false;
    }
    //check top-left
    int a=r, b=c;
    while(a>=0 && b>=0){
        if(grid[a][b]=='Q')return false;
        a--; b--;
    }
    //check botom-left
    a=r, b=c;
    while(a<n && b>=0){
        if(grid[a][b]=='Q')return false;
        a++; b--;
    }
    return true;
}

void place_queens(int id, int n,vector<string>&grid, vector<vector<string>>&ans){
    //id is column
    if(id == n){
        ans.push_back(grid);
        return;
    }
    for(int i = 0; i<n; ++i){
        if(safe_pos(i,id,grid)){
            grid[i][id] = 'Q';
            place_queens(id+1,n,grid,ans);
            grid[i][id] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<string>grid;
    string str;
    for(int i = 0; i < n; ++i){
        str.push_back('.');
    }
    for(int i = 0; i < n; ++i){
        grid.push_back(str);
    }
    place_queens(0,n,grid,ans);
    return ans;
}

int main(){
    vector<vector<string>>ans = solveNQueens(2);
    for(auto vec: ans){
        for(auto i : vec){
            cout << i << endl;
        }
        cout << endl;
    }
    return 0;
}