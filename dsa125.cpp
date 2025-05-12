#include <bits/stdc++.h>
using namespace std;

void make_str(vector<string> &vec, string str, int open_brac, int close_brac, int n){
    if(open_brac == n && close_brac == n){
        str.push_back(')');
        vec.push_back(str);
        return;
    }
    if(open_brac != n && open_brac >= close_brac ){
        str.push_back('(');
        make_str(vec, str, ++open_brac,close_brac, n);
        str.pop_back();
        str.push_back(')');
        make_str(vec, str, --open_brac, ++close_brac, n);
    }
    else if(open_brac < close_brac){
        str.push_back('(');
        make_str(vec,str, ++open_brac, close_brac, n);
    }
    else if(open_brac > close_brac){
        str.push_back(')');
        make_str(vec, str, open_brac, ++close_brac, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> vec;
    string str = "(";
    make_str(vec, str, 1, 1, n);
    return vec;
}

int main(){
    vector<string> vec = generateParenthesis(1);
    for(auto i : vec){
        cout << i << endl;
    }
    return 0;
}