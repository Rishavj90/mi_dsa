#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans;
    for(int j =0; j < strs[0].size(); j++){
        bool flag = true;
        for(int i = 0; i < strs.size()-1; i++){
            if(strs[i][j] != strs[i+1][j]){
                flag = false;
                break;
            }
        }
        if(flag == true){
            ans = ans + strs[0][j];
        }else{
            break;
        }
    }
    return ans;   
}

int main(){
    vector<string> vec = {"flower","flow","flight"};
    cout << longestCommonPrefix(vec);
    return 0;
}