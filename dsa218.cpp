#include <bits/stdc++.h>
using namespace std;

vector<int> minPartition(int N) {
    vector<int>coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int>ans;
    for(int i = coins.size()-1; i>=0; i--){
        int a = N/coins[i];
        while(a--)ans.push_back(coins[i]);
        N%=coins[i];
    }
    return ans;
}

int main(){
    vector<int>ans = minPartition(50);
    for(auto i : ans)cout << i << " ";
    return 0;
}