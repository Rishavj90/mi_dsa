#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    vector<pair<int, string>> vec;
    vec = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400,"CD"}, {100, "C"},
        {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"},
        {4, "IV"}, {1, "I"}
    };
    int x = num;
    string ans;
    for(int i = 0; i < vec.size(); i++){
        if(x == 0) break;
        int times = x/vec[i].first;
        for(int j = 0; j < times; j++){
            ans += vec[i].second; 
        }
        x %= vec[i].first;
    }
    return ans;
}

int main(){
    int num = 9;
    string s = intToRoman(num);
    cout << s;
    return 0;
}