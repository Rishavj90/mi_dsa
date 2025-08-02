#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    //g : kids greed, s: cookie
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int ans = 0;
    int i = 0, j = 0;
    while(i<g.size()){
        if(j >= s.size())break;
        if(g[i] <= s[j]){
            i++;
            ans++;
        }
        j++;
    }
    return ans;
}