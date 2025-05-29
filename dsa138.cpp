#include <bits/stdc++.h>
using namespace std;

//0: A blocked cell, 1: A free cell
void move_rat(int x, int y, string& path,vector<string>&ans, vector<vector<int>>& maze){
    vector<pair<int,int>>direction = {{1,0},{0,-1},{0,1},{-1,0}}; //down,left,right,Up
    vector<char>dir = {'D','L','R','U'};

    if(x >= maze.size() || y >= maze.size() || x < 0 || y < 0 || maze[x][y] == 0 || maze[x][y] == '$')return;
    
    if(x == maze.size()-1 && y == maze.size()-1){
        ans.push_back(path);
        return;
    }
    maze[x][y] = '$';
    for(int i = 0; i < direction.size(); ++i){
        int new_x = x+direction[i].first;
        int new_y = y+direction[i].second;
        path.push_back(dir[i]);
        move_rat(new_x,new_y,path,ans,maze);
        path.pop_back();
    }
    maze[x][y] = 1;
}


vector<string> ratInMaze(vector<vector<int>>& maze) {
    string path;
    vector<string> ans;
    move_rat(0,0,path,ans,maze);
    return ans;
}

int main(){
    vector<vector<int>> maze = {{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
    vector<string> vec = ratInMaze(maze);
    for(auto i : vec){
        cout << i << " ";
    }
    return 0;
}