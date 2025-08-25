#include <bits/stdc++.h>
using namespace std;

//O(nlogn + n)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>>ans;
    int i = 0, n = intervals.size();
    while(i < n){
        int start = intervals[i][0], end = intervals[i][1];
        while((i+1) < n && end >= intervals[i+1][0]){
            end = max(end, intervals[i+1][1]);
            i++;
        }
        ans.push_back({start, end});
        i++;
    }
    return ans;
}

int main(){
    vector<vector<int>>vec = {{1,4},{0,0}};
    vector<vector<int>>ans = merge(vec);
    for(auto i : ans){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}