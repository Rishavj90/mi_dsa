#include <bits/stdc++.h>
using namespace std;

//recursive soln
long long recur_myAtoi(string s, int j, long long ans) {
    if(j >= s.length()) return ans;
    int num;
    num = s[j]-'0';
    if(num >= 0 && num <= 9){
        if(ans >= LLONG_MAX/10 || ans == LLONG_MAX/10) return LLONG_MAX;
        return recur_myAtoi(s, j+1, ans*10 + num);
    }
    return ans;
}

int myAtoi(string s) {
    int i = 0;
    int sign = 1;
    //ignore white space
    while(s[i] == ' '){
        i++;
    }
    //check for sign
    if(s[i] == '-'){
        sign = -1;
        i++;
    }else if(s[i] == '+'){
        sign = 1;
        i++;
    }
    //convert
    long long ans = recur_myAtoi(s, i,0);
    ans*= sign;
    //keep it <=INT_MAX and >=INT_MIN
    if(ans >= INT_MAX) return INT_MAX;
    else if(ans <= INT_MIN) return INT_MIN;
    return (int)ans;
}
int main(){
    string s = "-91283472332";
    cout << myAtoi(s);
    return 0;
}