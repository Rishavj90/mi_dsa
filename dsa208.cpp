#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int>vec(26,0);
    for(auto i : tasks)vec[i-'A']++;

    priority_queue<int>pq;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] > 0)pq.push(vec[i]);
    }

    int time = 0;
    while(!pq.empty()){
        vector<int>tmp;
        int k = n+1;
        while(k-- && !pq.empty()){
            int a = pq.top();
            pq.pop();
            a--;
            tmp.push_back(a);
        }
        for(auto i : tmp){
            if(i>0){
                pq.push(i);
            }
        }
        if(pq.empty())time+=tmp.size();
        else time+=(n+1);
    }
    return time;
}   

    
  
int main(){
    vector<char>tasks = {'A','A','A','B','B','B'};
    cout << leastInterval(tasks, 2);
    return 0;
}