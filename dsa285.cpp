#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    
    vector<int>vec(n,0);
    vector<vector<int>>visited(m,vec);

    for(int i = 0; i<m; i++){
        if(board[i][0] == 'O'){
            dfs(i, 0, board, visited);
        }
        if(board[i][n-1] == 'O'){
            dfs(i, n-1, board, visited);
        }
    }

    for(int i = 0; i<n; i++){
        if(board[0][i] == 'O'){
            dfs(0, i, board, visited);
        }
        if(board[m-1][i] == 'O'){
            dfs(m-1, i, board, visited);
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == 'O' && visited[i][j] == 0){
                board[i][j] = 'X';
            }
        }
    }
    
    return;
}

void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& visited){
    int m = board.size(), n = board[0].size();
    visited[i][j] = 1;
    vector<int>move = {1,0,-1,0};
    for(int a = 0; a<4; a++){
        int g = i+move[a], h = j+move[3-a];
        if(g>=0 && g<m && h>=0 && h<n && board[g][h] == 'O' && visited[g][h] == 0){
            dfs(g,h,board,visited);
        }
    }

}

