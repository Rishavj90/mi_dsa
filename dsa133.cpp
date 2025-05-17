#include <bits/stdc++.h>
using namespace std;

void make_string(vector<string>&vec,string &curr,unordered_map<char,vector<char>>&keypad,string &digits, int k){
    if(digits.size()==0)return;
    if(k == digits.length()){
        vec.push_back(curr);
        return;
    }
    for(int i = 0; i < keypad[digits[k]].size();++i){
        curr.push_back(keypad[digits[k]][i]);
        make_string(vec,curr,keypad,digits,k+1);
        curr.pop_back();
    }
}

void keypad_func(unordered_map<char,vector<char>>&keypad){
    char j = '2';
    int i = 0;
    while(i <25){
        int k = 3;
        if('a'+i=='s'){
            keypad['7'].push_back('s');
            i++;
        }
        while(k--){
            keypad[j].push_back('a'+i);
            i++;
        }
        j=j+1;
    }
    keypad['9'].push_back('z');
    return;
}

vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<char>>keypad;
    keypad_func(keypad);
    vector<string>vec;
    string curr;
    make_string(vec,curr,keypad,digits,0);
    return vec;
}

int main(){
    string digits = "";
    vector<string> vec = letterCombinations(digits);
    for(auto str : vec){
        cout << str << endl;
    }
    return 0;
}