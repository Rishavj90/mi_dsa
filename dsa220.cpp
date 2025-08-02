#include <bits/stdc++.h>
using namespace std;

//'*' could be treated as ')' or '(' or an empty string "".
bool checkValidString(string s) {
    int maxB = 0, minB = 0;
    for(int i = 0; i< s.length(); i++){
        if(s[i]=='('){
            maxB++;
            minB++;
        }else if(s[i] ==')'){
            if(minB>0)minB--;
            if(maxB>0)maxB--;
            else return false;
        }else{
            if(minB>0)minB--;
            maxB++;
        }
    }
    if(minB == 0)return true;
    return false;
}

int main(){
    string s = "";
    cout << checkValidString(s);
    return 0;
}