#include <bits/stdc++.h>
using namespace std;

//operators : +, -, *, /, %, ^
//operands : a to z, A to Z

string preToInfix(string pre_exp) {
    stack<string> stk_num;
    stack<string> stk_op;

    for(int i = pre_exp.length()-1; i >= 0; --i){
        string char_str;
        char_str += pre_exp[i];

        if(pre_exp[i] >= 'a' && pre_exp[i] <= 'z')stk_num.push(char_str);
        else if(pre_exp[i] >= 'A' && pre_exp[i] <= 'Z')stk_num.push(char_str);
        else{
            stk_op.push(char_str);

            string new_num = "(";
            new_num += stk_num.top(); //add one operand
            new_num += stk_op.top();  //add one operator 
            stk_num.pop();
            stk_op.pop();
            new_num += stk_num.top(); //add second operand
            stk_num.pop();
            new_num += ")";

            stk_num.push(new_num);
        }
    }
    return stk_num.top();
}

int main(){
    string pre_exp = "*-A/BC-/AKL";
    cout << preToInfix(pre_exp);
    return 0; 
}