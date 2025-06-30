#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& mat) {
    int a = 0, b = mat[0].size()-1;
    while(a<b){
        if(mat[a][b] == 1)a++;
        else if(mat[b][a] == 1)b--;
        else{
            a++;
            b--;
        }
    }
    for(int i = 0; i < mat.size(); i++){
        if(a==i)continue;
        if(mat[a][i] != 0 || mat[i][a] != 1)return -1;
    }
    return a;
}
int main(){
    vector<vector<int>>mat = {
        {1, 0, 1},
        {0, 1, 1},
        {1, 0, 1}
    };
    cout << celebrity(mat);
    return 0;
}