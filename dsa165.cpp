#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char>stk;
    stk.push(s[0]);
    vector<char>brac = {'(', ')', '{','}', '[', ']'};
    for(int i = 1; i < s.length(); ++i){
        bool flag_push = true;
        for(int j = 0; j < brac.size(); j+=2){
            if(!stk.empty() && stk.top() == brac[j] && s[i] == brac[j+1]){
                stk.pop();
                flag_push = false;
                break;
            }
        }
        if(flag_push)stk.push(s[i]);
    }
    if(stk.empty())return true;
    return false;
}

int main(){
    cout << isValid("()[]{}");
    return 0;
}