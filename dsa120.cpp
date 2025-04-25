#include <bits/stdc++.h>
using namespace std;

double recur_pow(double x,long long n){
    if(n == 0) return 1;
    if(n%2 == 1)return x * recur_pow(x, n-1);
    return recur_pow(x*x, n/2);
}

double myPow(double x, int n) {
    long long m = n;
    int sign = 1;
    double ans;
    if(m < 0){
        sign = -1;
        ans = 1/recur_pow(x, sign*m);
        return ans;
    }
    ans = recur_pow(x, m);
    return ans;
}