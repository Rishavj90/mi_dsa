#include <bits/stdc++.h>
using namespace std;

string preToPost(string pre_exp) {
    stack<string> stk_num;

    for(int i = pre_exp.length()-1; i >= 0; --i){
        string char_str;
        char_str += pre_exp[i];

        if(pre_exp[i] >= 'a' && pre_exp[i] <= 'z')stk_num.push(char_str);
        else if(pre_exp[i] >= 'A' && pre_exp[i] <= 'Z')stk_num.push(char_str);
        else{
            string new_num = "";
            new_num += stk_num.top(); //add one operand 
            stk_num.pop();
            new_num += stk_num.top(); //add second operand
            stk_num.pop();
            new_num += char_str; //add operator

            stk_num.push(new_num);
        }
    }
    return stk_num.top();
}

int main(){
    string pre_exp = "*-A/BC-/AKL";
    cout << preToPost(pre_exp);
    return 0;
}