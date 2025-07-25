#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0; i < hand.size(); i++)pq.push(hand[i]);
    
    while(!pq.empty()){
        int k = groupSize;
        vector<int>tmp;
        int prev = INT_MIN;
        while(k--){
            int next = pq.top();
            while(next == prev){
                tmp.push_back(next);
                if(!pq.empty())pq.pop();
                else return false;
                next = pq.top();
            }
            if(k<(groupSize-1) && next > prev+1)return false;
            prev = next;
            if(!pq.empty())pq.pop();
            else return false;
        }
        for(auto i : tmp)pq.push(i);
    }
    return true;
}

int main(){
    vector<int>hand = {1,2,3,4,5,6};
    string output = (isNStraightHand(hand, 2) == true) ? "True" : "False";
    cout << output;
    return 0;
}