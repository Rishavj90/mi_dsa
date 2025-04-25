#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, bottom=n-1, left=0, right=m-1;
    vector<int> ans;
    while(top <= bottom && left <= right){
        for(int i = left; i<= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> vec = {{1,2},{4,3}};
    for(auto i1 : vec){
        for(auto i2 : i1){
            cout << i2 << " ";
        }
        cout << endl;
    }
    vector<int> vec2 = spiralOrder(vec);
    for(auto i : vec2){
        cout << i << " ";
    }
    return 0;
}