#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    //Ignore any leading whitespace
    int i = 0;
    while(i < s.length() && s[i] == ' '){i++;}
    //check sign
    bool sign = true;
    if(s[i] == '-'){
        sign = false;
        i++;
    }else if(s[i] == '+') i++;
    //calculating num
    long long num = 0;
    while(i<s.length() && s[i] >= '0' && s[i] <= '9'){
        num = num*10 + (s[i] - '0');
        if(sign == false){
            if(-1*num < INT_MIN) return INT_MIN;
        }else if(num > INT_MAX) return INT_MAX;
        i++;
    }
    if(sign == false){
        return (int) -1*num;
    }
    return (int) num;
}

int main(){
    string s = "  -042";
    cout << myAtoi(s);
    return 0;
}