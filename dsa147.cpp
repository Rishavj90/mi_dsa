#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    long long num = dividend, denum = divisor, quotient = 0, flag = 1;
    if(num < 0){
        num *= -1;
        flag *= -1;
    }
    if(denum < 0){
        denum *= -1;
        flag *= -1;
    }
    while(num >= denum){
        int b = 0;
        while(denum *((long long)1 << b+1) < num){
            b++;
        }
        long long a = (long long)1 << b;
        num -= (denum * a);
        quotient +=  a;
    }
    if(flag*quotient < INT_MIN)return INT_MIN;
    if(flag*quotient > INT_MAX)return INT_MAX; 
    return flag*quotient;
}

int main(){
    int num = INT_MIN, denum = 1;
    cout << divide(num,denum) << " == " << num/denum;
    return 0;
}