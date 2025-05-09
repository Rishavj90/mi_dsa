#include <bits/stdc++.h>
using namespace std;

void recursive_validStrings(int n, string str, vector<string>&vec) {
    if(n<=0){
        vec.push_back(str);
        return;
    }
    if(str.length() == 0 || str.length() > 0 && str[str.length()-1] == '1'){
        int i = 0;
        while(i < 2){
            char num = '0'+ i;
            str.push_back(num);
            i++;
            recursive_validStrings(--n, str, vec);
            ++n;
            str.pop_back();
        }
    }
    if(str.length() > 0 && str[str.length()-1] == '0'){
        str.push_back('1');
        recursive_validStrings(--n, str, vec);
        ++n;
        str.pop_back(); 
    }
}

vector<string> validStrings(int n) {
    //Without Adjacent Zeros
    string str;
    vector<string> vec;
    recursive_validStrings(n, str,vec);
    return vec;
}

int main(){
    vector<string> ans = validStrings(3);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}