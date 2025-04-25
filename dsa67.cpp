#include <bits/stdc++.h>
using namespace std;

bool placeCows(vector<int> &stalls, int dis, int k){
    sort(stalls.begin(), stalls.end());
    int j = 0;
    k--;
    for(int i = 1; i < stalls.size(); i++){
        if(stalls[j] + dis <= stalls[i]){
            j = i;
            k--;
        }
        if( k == 0){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    int low = 1; int high = INT_MAX;
    while(low<= high){
        int mid = low + (high - low)/2;
        bool opinion = placeCows(stalls, mid, k);
        if(opinion == false){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return high;
}

int main(){
    vector<int> stalls = {2, 12, 11, 3, 26, 7};
    cout << aggressiveCows(stalls, 5);
    return 0;
}