#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k) {
    int l = 0,r = 0;
    int unq = 0;
    int maxLen = -1;
    vector<int>alp(26,0);
    while(r < s.length()){
        int i = s[r]-'a';
        if(alp[i] == 0)unq++;
        alp[i]++;
        while(unq > k){
            int j = s[l]-'a';
            alp[j]--;
            if(alp[j] == 0)unq--;
            l++;
        }
        if(unq==k)maxLen = (r-l+1)>maxLen ? (r-l+1) : maxLen;
        r++;
    }
    return maxLen;
}

int main(){
    string s = "aabaaab";
    cout << longestKSubstr(s,2);
    return 0; 
}