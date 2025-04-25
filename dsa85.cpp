#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s){
    unordered_map<char, int> mpp;
    mpp = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    long long sum = mpp[s[s.length() - 1]];
    for(int i = s.length()-2; i >= 0; i--){
        if(mpp[s[i]] < mpp[s[i+1]]){
            sum-= mpp[s[i]];
        }else{
            sum+= mpp[s[i]];
        }
    }
    return sum;
}
int main(){
    string s = "MCMXCIV";
    cout << romanToInt(s);
    return 0;
}