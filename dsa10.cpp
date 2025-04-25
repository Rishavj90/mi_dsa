#include <bits/stdc++.h>
using namespace std;

int fac(int n){
    if(n==1) return 1;
    return n*fac(n-1); 
}
void factorialNumbers(int n){
    for(int i = 1; i < n; ++i){
        int factorial = fac(i);
        if(factorial <= n){
            cout << factorial << " ";
        }else{
            break;
        }
    }
}

int main(){
    int a;
    cin >> a;
    factorialNumbers(a);
    return 0;
}