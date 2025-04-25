#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    vector<int> vec(26,0);
    for(int i =0; i< s.length(); i++){
        int j = s[i] - 'a';
        vec[j]++;
    }
    for(int i =0; i< t.length(); i++){
        int j = t[i] - 'a';
        if(vec[j] == 0){
            return false;
        }else{
            vec[j]--;
        }
    }
    return true;
}
int main(){
    string a = "anaoram";
    string b = "nagaram";
    cout << isAnagram(a, b);
    return 0;
}