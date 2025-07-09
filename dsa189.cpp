#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0, maxLen = 0;
    unordered_map<char, int>mpp;
    while(r < s.length()){
        if(mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l ) l = mpp[s[r]]+1;
        maxLen = (r-l+1) > maxLen ? (r-l+1) : maxLen;
        mpp[s[r]] = r;
        r++;
    }
    return maxLen;
}

int main(){
    string s = "abba";
    cout << lengthOfLongestSubstring(s);
    return 0;
}