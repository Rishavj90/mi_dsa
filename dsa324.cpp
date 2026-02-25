#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int minCost(vector<int>& height) {
    int n=height.size();
    if (n == 1) return 0;

    int tmp2 = 0, tmp1 = abs(height[1]-height[0]);

    for(int i=2; i<n; i++){
        int from1 = tmp1+ abs(height[i-1]-height[i]);
        int from2 = tmp2+ abs(height[i-2]-height[i]);
        int newTmp = min(from1, from2);
        tmp2=tmp1;
        tmp1=newTmp;

    }
    return tmp1;

}

};


