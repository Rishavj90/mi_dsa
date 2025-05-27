#include <bits/stdc++.h>
using namespace std;

bool find_str(int r, int c, int index,vector<vector<char>>& board, string word){
    int rows = board.size(), columns = board[0].size();
    if(index == word.length())return true;
    if(r>=rows||c>=columns||r<0||c<0||board[r][c]=='$'||board[r][c]!=word[index])return false;
    vector<pair<int, int>>vec = {{1,0},{0,1},{-1,0},{0,-1}};
    
    char temp = board[r][c];
    board[r][c] = '$';
    for(auto i : vec){
        if(find_str(r+i.first,c+i.second,index+1,board,word))return true;
    }
    board[r][c] = temp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size(), columns = board[0].size();
    vector<pair<int, int>> vec;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            if(board[i][j] == word[0])vec.push_back({i, j});
        }
    }
    for(auto i : vec){ 
        if(find_str(i.first, i.second,0,board,word))return true;
    }
    return false;
}

int main(){
    string word = "SADD";
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    cout << true << " : true " << false << " : false" << endl;
    cout << exist(board,word);
    return 0;
}