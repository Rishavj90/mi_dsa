#include <bits/stdc++.h>
using namespace std;

int beautySum(string s) {
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        unordered_map<char, int>mpp;
        for(int j = i; j < s.length(); j++){
            mpp[s[j]]++;
            if(mpp.size() > 1){
                int max_beauty = INT_MIN, min_beauty = INT_MAX;
                for(auto k : mpp){
                    if(k.second > max_beauty) max_beauty= k.second;
                    if(k.second < min_beauty) min_beauty= k.second;
                }
                ans += max_beauty - min_beauty;
            }
        }
    }
    return ans;
}

int main(){
    string str = "aabcbaa";
    cout << beautySum(str);
    return 0;
}