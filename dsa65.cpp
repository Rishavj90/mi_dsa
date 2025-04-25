#include <bits/stdc++.h>
using namespace std;

int reqDays(vector<int>& weights, int wt_cap){
    long long load = 0, days = 1;
    for(int i = 0; i < weights.size(); i++){
        if(load + weights[i] > wt_cap){
            days++;
            load = weights[i];
        }else{
            load += weights[i];
        }
    }
    return days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    long long high = 0;
    for(int i = 0; i < weights.size(); i++){
        high+= weights[i];
    }
    while(low <= high){
        int mid = low + (high - low)/2;
        int d = reqDays(weights, mid);
        if(d <= days){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout << shipWithinDays(weights, 5);
    return 0;
}