#include <bits/stdc++.h>
using namespace std;

string infixToPostfix(string& s) {
    string str;
    stack<char>stk;
    unordered_map<char,int> priority = {{'^', 3},{'*', 2},{'/', 2},{'+', 1},{'-', 1}};
    for(int i = 0; i< s.length(); ++i){
        if(s[i] >= 'a' && s[i] <= 'z')str.push_back(s[i]);
        else if(s[i] >= 'A' && s[i] <= 'Z')str.push_back(s[i]);
        else if(s[i] >= '0' && s[i] <= '9')str.push_back(s[i]);
        else{
            while(s[i] != '(' && s[i] != ')' && !stk.empty() && priority[s[i]] <= priority[stk.top()]){
                str.push_back(stk.top());
                stk.pop();
            }
            stk.push(s[i]);

            if(stk.top() == ')'){
                stk.pop();
                while(stk.top() != '('){
                    str.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }
        }
    }
    while(!stk.empty()){
        str.push_back(stk.top());
        stk.pop();
    }
    return str;
}

int main(){
    string s = "h^m^q^(7-4)";
    string a = infixToPostfix(s);
    cout << a;
    return 0;
}