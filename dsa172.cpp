#include <bits/stdc++.h>
using namespace std;

string infixToPre(string infix_exp) {
    reverse(infix_exp.begin(), infix_exp.end());
    for(int i = 0; i<infix_exp.length(); ++i){
        if(infix_exp[i] == ')')infix_exp[i] = '(';
        else if(infix_exp[i] == '(')infix_exp[i] = ')';
    }

    //find postfix
    string str;
    stack<char>oper;
    unordered_map<char, int>priority = {{'+',1}, {'-',1},{'*',2},{'/',2},{'^',3}};
    for(int i = 0; i < infix_exp.length(); ++i){
        if(infix_exp[i] >= 'a' && infix_exp[i] <= 'z')str+=infix_exp[i];
        else if(infix_exp[i] >= 'A' && infix_exp[i] <= 'Z')str+=infix_exp[i];
        else if(infix_exp[i] >= '0' && infix_exp[i] <= '9')str+=infix_exp[i];
        else if(infix_exp[i] == '(')oper.push(infix_exp[i]);
        else if(infix_exp[i] == ')'){
            while(oper.top() != '('){
                str += oper.top();
                oper.pop();
            }
            oper.pop();
        }else{
            while(!oper.empty() && oper.top() != '(' && priority[oper.top()] > priority[infix_exp[i]]){
                str+=oper.top();
                oper.pop();
            }
            oper.push(infix_exp[i]);
        }
    }
    while(!oper.empty()){
        str += oper.top();
        oper.pop();
    }

    reverse(str.begin(), str.end());
    return str;
}


int main(){
    string exp = "(a+b)*c-d+f";
    cout << infixToPre(exp);
    return 0;
}