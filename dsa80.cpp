#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    map<char, char> mpp1;
    map<char, char> mpp2;
    for(int i =0; i < s.length(); i++){
        auto pin_s = mpp1.find(s[i]);
        auto pin_t = mpp2.find(t[i]);
        if(pin_s == mpp1.end() && pin_t == mpp2.end()){
            mpp1.insert({s[i], t[i]});
            mpp2.insert({t[i], s[i]});
        }else if(mpp1[s[i]] != t[i] && mpp2[t[i]] != s[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string a = "paper";
    string b = "title";
    cout << true << " : True " << false << " : False" << endl;
    cout << isIsomorphic(a, b);
    return 0;
}