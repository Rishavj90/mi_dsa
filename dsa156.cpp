#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<int>vec(n+1,1);
    if(n>1){vec[0] = 0, vec[1] = 0;}
    int cnt = 0;
    for(int i = 2; i < n; ++i){
        if(vec[i]==1){
            cnt++;
            for(long k = i*i; k < n; k+=i){
                vec[k] = 0;
            }
        }
    }
    return cnt;
}

int main(){
    int a = countPrimes(1520);
    cout << endl << a;
    return 0;
}
