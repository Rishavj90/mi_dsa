#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int low = 1, high = *max_element(piles.begin(),piles.end());
    while(low <= high){
        int mid = (long long)(low+high)/2;
        int num= 0;
        for(int i = 0; i < n; i++){
            num+= (piles[i]/mid);
            if(piles[i] % mid != 0){
                num++;
            }
        }
        if(num <= h){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> vec = {159061844,517725047,376711793,557608450,386051217,915761849,443805917,541997964,420003629};
    cout << minEatingSpeed(vec, 771473915);
    return 0;
}