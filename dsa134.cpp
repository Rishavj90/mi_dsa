#include <bits/stdc++.h>
using namespace std;

bool check_palindrome(string str){
    bool is_palindrome = true;
    for(int i = 0; i < str.length(); ++i){
        if(str[i] != str[str.length()-1-i]){
            is_palindrome = false;
            break;
        }
    }
    return is_palindrome;
}

void make_partition(int index,string s,vector<string>&curr, vector<vector<string>>&ans){
    if(index >= s.length()){
        ans.push_back(curr);
        return;
    }
    for(int i = 1; i <= s.length()-index; ++i){
        string sub_str = s.substr(index,i);
        if(check_palindrome(sub_str)==true){
            curr.push_back(sub_str);
            make_partition(index+i,s,curr,ans);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> curr;
    make_partition(0,s,curr,ans);
    return ans;
}

int main(){
    string s = "bahhab";
    vector<vector<string>> ans = partition(s);
    for(auto vec : ans){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}