#include <bits/stdc++.h>
using namespace std;

double find_pow(double ans, double x, long n) {
    if(n ==0)return ans;
    if((n & 1) == 0){
        return find_pow(ans, x*x, n>>1);
    }
    return find_pow(ans*x, x, n-1);
}

double myPow(double x, int n) {
    if(n < 0){
        return (1/find_pow(1, x, -1*(long)n));
    }
    return find_pow(1,x,(long)n);
}

int main(){
    cout << myPow(5.9,-7);
    return 0;
}