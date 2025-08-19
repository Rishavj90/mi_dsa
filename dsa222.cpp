#include <bits/stdc++.h>
using namespace std;

/*
static bool customComp(pair<int,int>a, pair<int,int>b){
    return a.second > b.second; 
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();
    vector<pair<int,int>>jobs;
    int maxDays = -1;
    for(int i = 0; i< n; i++){
        maxDays = (deadline[i] > maxDays) ? deadline[i] : maxDays;
        jobs.push_back({deadline[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end(), customComp);
    vector<bool>timeTable(maxDays+1,false);
    int ans_jobs = 0, ans_profit = 0;
    for(auto i : jobs){
        int day = i.first;
        int myProfit = i.second;
        while(day>0 && timeTable[day])day--;
        if(day>0){
            timeTable[day] = true;
            ans_jobs++;
            ans_profit+=myProfit;
        }
    }
    
    return {ans_jobs, ans_profit};
}
*/

