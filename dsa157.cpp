#include <bits/stdc++.h>
using namespace std;

vector<int> findPrimeFactors(int N) {
    vector<int>vec(N+1);
    for(int i = 0; i < N+1; ++i)vec[i]=i;
    vector<int>factors;
    for(int i = 2; i <= N; ++i){
        if(vec[i] == i){
            for(int j = i*i; j<=N; j+=i){
                if(vec[j]>i)vec[j]=i;
            }
        }
    }
    while(N != 1){
        factors.push_back(vec[N]);
        N/=vec[N];
    }
    return factors;
}

int main(){
    vector<int>vec = findPrimeFactors(1);
    for(auto i : vec){
        cout << i << " ";
    }
    return 0;
}