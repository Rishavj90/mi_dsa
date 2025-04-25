#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    int i = num.length() - 1;
    while(i >= 0){
        int n = num[i] - '0';
        if(n%2 == 1){
           return num.substr(0, i+1);
        }
        i--;
    }
    return "";
}

int main(){
    string s = "35427";
    cout << largestOddNumber(s);
    return 0;
}