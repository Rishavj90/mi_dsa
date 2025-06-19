#include <bits/stdc++.h>
using namespace std;

string postToPre(string post_exp) {
    stack<string> stk_num;

    for(int i = 0; i < post_exp.length(); ++i){
        string char_str;
        char_str += post_exp[i];

        if(post_exp[i] >= 'a' && post_exp[i] <= 'z')stk_num.push(char_str);
        else if(post_exp[i] >= 'A' && post_exp[i] <= 'Z')stk_num.push(char_str);
        else{
            string num_2 = stk_num.top();
            stk_num.pop();
            string num_1 = stk_num.top();
            stk_num.pop();
            
            string new_num = char_str + num_1 + num_2;
            stk_num.push(new_num);
        }
    }
    return stk_num.top();
}

int main(){
    string post_exp = "ABC/-AK/L-*";
    cout << postToPre(post_exp);
    return 0;
}