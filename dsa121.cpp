#include <bits/stdc++.h>
using namespace std;

long long recur_pow(long long x,long long n){
    int num = 1e9+7;
    if(n == 0) return 1;
    if(n%2 == 1)return (x * recur_pow(x, n-1))%num;
    return recur_pow((x*x)%num, n/2);
}

int countGoodNumbers(long long n) {
    int num = 1e9+7;
    long long five_pow = 0;
    if(n%2 == 0){
        five_pow = n/2;
    }else{
        five_pow = n/2 + 1;
    }
    long long five_multiple = recur_pow(5, five_pow);
    long long four_multiple = recur_pow(4, n-five_pow);
    int ans = (five_multiple*four_multiple)%num;
    return ans;
}

int main(){
    long long n = 8619766238294788754;
    cout << countGoodNumbers(n);
    return 0;
}