#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& bt) {
    sort(bt.begin(), bt.end());
    long long wt = 0, ans = 0;
    for(int i =0; i< bt.size()-1;i++){
        wt+=bt[i];
        ans+=wt;
    }
    ans/=bt.size();
    return ans;
}

int main(){
    vector<int>vec = {4,3,7,1,2};
    cout << solve(vec);
    return 0;
}