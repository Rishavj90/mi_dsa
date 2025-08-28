#include <bits/stdc++.h>
using namespace std;

bool customComp(vector<int>&a, vector<int>&b){
    if(a[1]==b[1])return a[0]<b[0];
    return a[1]<b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end(), customComp);
    int i = 0, j = 1, n = intervals.size();
    int ans = 0;
    while(j < n){
        if(intervals[i][1] > intervals[j][0])ans++;
        else i = j;
        j++;
    }
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    cout << eraseOverlapIntervals(intervals);
    return 0;
}