#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    vector<int>vec(matrix[0].size(),0);
    int max_area = INT_MIN;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < vec.size(); j++){
            if(matrix[i][j] == '1')vec[j]++;
            else vec[j] = 0;
        }
        stack<pair<int, int>>stk; //{height,index}
        for(int j = 0; j < vec.size(); j++){
            int index = j;
            while(!stk.empty() && stk.top().first >= vec[j]){
                index = stk.top().second;
                int ht = stk.top().first;
                int area = ht*(j-index);
                max_area = max_area < area ? area : max_area;
                stk.pop();
            }
            stk.push({vec[j],index});
        }
        while(!stk.empty()){
            int ht = stk.top().first;
            int index = stk.top().second;
            int area = ht*(vec.size()-index);
            max_area = area > max_area ? area : max_area;
            stk.pop();
        }
    }
    return max_area;
}

int main(){
    vector<vector<char>>matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << maximalRectangle(matrix);
    return 0;
}