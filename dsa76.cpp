#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    vector<char> vec;
    string ans;
    for(int i = 0; i < s.length() ;i++){
        if(vec.empty()){
            vec.push_back(s[i]);
            continue;
        }
        if(s[i] == '('){
            vec.push_back(s[i]);
            ans.push_back(s[i]);
        }else{
            vec.pop_back();
            if(!vec.empty()){
                ans.push_back(s[i]);
            }
        }
    }
    return ans;
}

int main(){
    string q = "(()())(())";
    cout << removeOuterParentheses(q);
    return 0;
}