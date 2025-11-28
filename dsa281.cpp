#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size(), n = image[0].size();
    int pixel = image[sr][sc];
    vector<int>vec(n,0);
    vector<vector<int>>visited(m,vec);

    queue<pair<int,int>>q;
    q.push({sr, sc});
    visited[sr][sc] = 1;

    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        image[r][c] = color;

        if(r-1 >=0 && image[r-1][c] == pixel && visited[r-1][c] == 0){
            q.push({r-1,c});
            visited[r-1][c] = 1;
        }

        if(r+1 <m && image[r+1][c] == pixel && visited[r+1][c] == 0){
            q.push({r+1,c});
            visited[r+1][c] = 1;
        }
        
        if(c-1 >=0 && image[r][c-1] == pixel && visited[r][c-1] == 0){
            q.push({r,c-1});
            visited[r][c-1] = 1;
        }
        
        if(c+1 <n && image[r][c+1] == pixel && visited[r][c+1] == 0){
            q.push({r,c+1});
            visited[r][c+1] = 1;
        }

    }

    return image;
    
}


