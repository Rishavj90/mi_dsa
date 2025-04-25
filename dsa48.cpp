#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for(int i =0; i < n; i++){
        int start = intervals[i][0];
        int end = intervals[i][1];
        if(ans.empty() || start > ans.back()[1]){
            ans.push_back({start, end});
        }else{
            ans.back()[1] = max(ans.back()[1], end);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> vec = {{1,3}, {2,6}, {5,8}, {10, 14}, {15, 17}};
    vector<vector<int>> vec2 = merge(vec);
    for(auto i : vec2){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}