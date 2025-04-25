#include <bits/stdc++.h>
using namespace std;

int countLessOrEqualTo(string& s, int b){
    int l = 0, r= 0, count = 0;
    unordered_map<char, int> mpp;
    while(l < s.length() && r < s.length()){
        mpp[s[r]]++;
        while(mpp.size() >b){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l++;
        }
        count += r-l+1;
        r++;
    }
    return count;
}
int countSubstr(string& s, int k) {
    return countLessOrEqualTo(s,k) - countLessOrEqualTo(s, k-1);
}
int main(){
    string str = "aba";
    cout << countSubstr(str,2);
    return 0;
}