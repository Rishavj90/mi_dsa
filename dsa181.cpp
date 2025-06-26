#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    if(k == num.size())return "0";
    stack<char>stk;
    for(int i =0; i<num.size(); i++){
        while(k>0 && !stk.empty() && stk.top()>num[i]){
            stk.pop();
            k--;
        }
        stk.push(num[i]);
    }
    while(!stk.empty() && k>0){
        stk.pop();
        k--;
    }
    string ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    int j =0;
    while(ans[j] == '0' && j < ans.size())j++;
    ans = ans.substr(j, ans.size()-j);
    if(ans.size() == 0)return "0";
    return ans;
}

int main(){
    string num = "33526221184202197273";
    cout << removeKdigits(num,19);
    return 0;
}