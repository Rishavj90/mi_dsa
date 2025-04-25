#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int max_len = 0, strt = 0;
    for(int i = 0; i < s.length(); i++){
        int k = i;
        while(k <= i+1){
            int l = i, r = k;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                if(max_len < r-l+1){
                    max_len = r-l+1;
                    strt = l;
                }
                l--;
                r++;
            }
            k++;
        }
    }
    return s.substr(strt, max_len);
}

int main(){
    string s = "cbbd";
    cout << longestPalindrome(s);
    return 0;
}