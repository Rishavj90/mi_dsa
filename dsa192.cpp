#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int l = 0, r = 0;
    int maxLen = 0;
    int mostFreq = 0;
    unordered_map<char, int>mpp;
    while(r < s.length()){
        mpp[s[r]]++;
        mostFreq = mpp[s[r]] > mostFreq ? mpp[s[r]] : mostFreq;
        int diff = (r-l+1) - mostFreq;
        if(diff <= k)maxLen = (r-l+1)>maxLen ? (r-l+1) : maxLen;
        else{
            mpp[s[l]]--;
            if(mpp[s[l]]==0)mpp.erase(s[l]);
            l++;
        }
        r++;
    }
    return maxLen;
}

int main(){
    string s = "AABABBA";
    cout << characterReplacement(s, 1);
}