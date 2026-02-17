#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<string> maxNumOfSubstrings(string s) {
    unordered_map<char, vector<int>>mpp;
    for(int i=0; i<s.size(); i++){
        char chr = s[i];
        if(!mpp[chr].empty())mpp[chr].pop_back();
        else mpp[chr].push_back(i);
        mpp[chr].push_back(i);
    }
    vector<vector<int>>intervals;
    for(auto &data : mpp){
        vector<int>vec=data.second;
        int start=vec[0], end=vec[1];
        char chr=s[start];
        int newEnd= end;
        bool valid=true;
        for(int i=start; i<=end; i++){
            if(s[i]==chr)continue;
            if(mpp[s[i]][0] < start){ valid = false; break; }
            newEnd = max(newEnd, mpp[s[i]][1]);
            end= (newEnd>end)? newEnd : end;
        }
        if(valid)intervals.push_back({start, newEnd});
    }

    sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    });

    //NOI : Non Overlapping Intervals
    vector<vector<int>>NOI;
    NOI.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); i++){
        int start=intervals[i][0];
        int end=intervals[i][1];
        int len = end-start+1;

        int prev_end = NOI[NOI.size()-1][1];
        int prev_start= NOI[NOI.size()-1][0];
        int prev_len = prev_end-prev_start+1;

        if(start > prev_end){
            NOI.push_back(intervals[i]);          // no overlap → always append
        } else if(end < prev_end){
            NOI.back() = {start, end};            // overlapping but smaller end → replace
        }
    }

    vector<string>ans;
    for(auto &interval : NOI){
        int start=interval[0], end=interval[1];
        ans.push_back(s.substr(start,end-start+1));
    }
    return ans;
}

};



