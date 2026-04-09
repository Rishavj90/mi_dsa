#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int minVal=INT_MAX, profit=0;
    for(int i=0; i<n; i++){
        minVal=min(minVal, prices[i]);
        profit= max(profit, prices[i]-minVal);
    }
    return profit;
}
};

