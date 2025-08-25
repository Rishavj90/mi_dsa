#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, 
                           vector<int>& newInterval) {
    vector<vector<int>>ans;
    int i = 0;
    while(i < intervals.size() && intervals[i][1] < newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }
    
    int start = newInterval[0], end = newInterval[1];
    while(i< intervals.size() && intervals[i][0] <= newInterval[1]){
        start = min(intervals[i][0], start);
        end = max(intervals[i][1], end);
        i++;
    }
    ans.push_back({start, end});

    while(i < intervals.size()){
        ans.push_back(intervals[i]);
        i++;
    }
    
    return ans;
}