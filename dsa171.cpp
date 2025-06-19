#include <bits/stdc++.h>
using namespace std;

string postToInfix(string exp) {
    stack<string> stk_num;

    for(int i = 0; i < exp.length(); ++i){
        string char_str;
        char_str += exp[i];

        if(exp[i] >= 'a' && exp[i] <= 'z')stk_num.push(char_str);
        else if(exp[i] >= 'A' && exp[i] <= 'Z')stk_num.push(char_str);
        else{
            string num_2 = stk_num.top();
            stk_num.pop();
            string num_1 = stk_num.top();
            stk_num.pop();
            
            string new_num = "(" + num_1 + char_str + num_2 + ")";
            stk_num.push(new_num);
        }
    }
    return stk_num.top();
}

int main(){
    string exp = "ab*c+";
    cout << postToInfix(exp);
    return 0;
}