#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices){
    int n = prices.size();
    int profit = 0, min = INT_MAX;
    for(int i = 0; i < n; i++){
        if(prices[i] < min) min = prices[i];
        profit = max(profit, prices[i]-min);
    }
    return profit;
}

int main(){
    vector<int> vec = {7,2,6,4,1,3,1};
    cout << maxProfit(vec);
    return 0;
}