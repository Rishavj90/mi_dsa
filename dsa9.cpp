#include <bits/stdc++.h>
using namespace std;


int sumOfSeries(int n){
    if(n>0){
        int a = 1;
        for(int i = 0; i < 3; ++i){
            a*=n;
        }
        return a + sumOfSeries(n-1);
    }
    return 0;
}

int main(){
    int a;
    cin >>a;
    cout << sumOfSeries(a);
    return 0;
}