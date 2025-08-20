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

class disjointSetUnion{
    vector<int>size, parent;
    public:
    disjointSetUnion(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i]=i;
        }
    }

    int FindMyParent(int a){
        if(a == parent[a])return a;
        return parent[a] = FindMyParent(parent[a]);
    }

    void unionSet(int a, int b){
        int par_a = FindMyParent(a);
        int par_b = FindMyParent(b);
        
        parent[par_a] = par_b;
    }
};

bool customComp(pair<int,int>a, pair<int,int>b){
    if(a.first == b.first)return a.second > b.second;
    return a.first > b.first;
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    vector<pair<int,int>>JobTimeline;
    int maxTime = 0;
    for(int i = 0; i< deadline.size(); i++){
        JobTimeline.push_back({profit[i] ,deadline[i]});
        maxTime = deadline[i]>maxTime ? deadline[i] : maxTime;
    }
    sort(JobTimeline.begin(), JobTimeline.end(), customComp);
    disjointSetUnion dsu(maxTime);
    
    int JobsDone = 0, myProfit = 0;
    for(auto i : JobTimeline){
        int money = i.first, JobDeadLine = i.second;
        int myTime = dsu.FindMyParent(JobDeadLine);
        if((myTime-1) >= 0){
            JobsDone++;
            myProfit+=money;
            dsu.unionSet(myTime, myTime-1);
        }
    }
    return {JobsDone, myProfit};
}

int main(){
    vector<int>deadline = {4, 1, 1, 1};
    vector<int>profit = {20, 10, 40, 30};
    vector<int>ans = jobSequencing(deadline, profit);
    for(auto i : ans)cout << i << " ";
    return 0;
}
