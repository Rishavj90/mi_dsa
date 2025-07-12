#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int>t_mpp;
    for(auto i : t)t_mpp[i]++;
    int need = t_mpp.size(), have = 0;

    unordered_map<char, int>s_mpp;
    int l = 0, r = 0, minWin = s.size();
    int start = -1, end = -1;
    
    while(r < s.size()){
        s_mpp[s[r]]++;
        if(s_mpp[s[r]] == t_mpp[s[r]])have++;
        while(have == need){
            if(minWin >= (r-l+1)){
                minWin = r-l+1;
                start = l;
                end = r;
            }
            s_mpp[s[l]]--;
            if(t_mpp[s[l]] > 0 && s_mpp[s[l]] < t_mpp[s[l]])have--;
            l++;
        }
        r++;
    }
    string res;
    if(start != -1 && end != -1)res = s.substr(start, (end-start+1));
    return res;
}

int main(){
    string s = "a";
    string t = "aa";
    cout << minWindow(s,t);
    return 0;
}