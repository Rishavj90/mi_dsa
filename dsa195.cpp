#include <bits/stdc++.h>
using namespace std;

 int numberOfSubstrings(string s) {
    int ans = 0;
    vector<int>vec(3,0);
    int l = 0, r= 0;
    while(r < s.length()){
        vec[s[r]-'a']++;
        while(vec[0]>0 && vec[1]>0 && vec[2]>0){
            ans += (s.length()-r);
            vec[s[l]-'a']--;
            l++;
        }
        r++;
    }
    return ans;
}

int main(){
    string s = "abcabc";
    cout << numberOfSubstrings(s);
    return 0;
}