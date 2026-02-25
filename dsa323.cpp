#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

int climbStairs(int n) {
    if(n<=2)return n;

    int prev1=1, prev2=2, curr=0;
    int k=n-2;
    while(k--){
        curr=prev1+prev2;
        prev1=prev2;
        prev2=curr;
    }
    return curr;
}

};


