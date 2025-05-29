#include <bits/stdc++.h>
using namespace std;

bool check_pos(int x, int y, int num, vector<vector<char>>& board){
    char a = '0';
    //check cube
    int start_x = (x/3)*3, start_y = (y/3)*3;
    for(int i = start_x; i < start_x+3; ++i){
        for(int j = start_y; j < start_y+3; ++j){
            if(board[i][j] == a+num)return false;
        }
    }
    for(int i = 0; i < 9; ++i){
        //check column
        if(board[i][y] == a+num)return false;
        //check row
        if(board[x][i] == a+num)return false;
    }
    return true;
}

bool put_num(int x, int y,vector<vector<char>>& board){
    if(x >= 9)return true;
    if(y == 9)return put_num(x+1,0,board);
    if(board[x][y] != '.')return put_num(x,y+1,board);
    for(int i = 1; i < 10; ++i){
        char a = '0';
        if(check_pos(x,y,i,board)){
            board[x][y] = a+i;
            if(put_num(x,y+1,board))return true;
            board[x][y] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    put_num(0,0,board);
}

int main(){
    vector<vector<char>>board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);
    for(auto vec : board){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}