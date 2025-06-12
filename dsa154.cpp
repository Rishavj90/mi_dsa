#include <bits/stdc++.h>
using namespace std;

int find_sqrt(int i){
    int low = 0, high = i;
    while(low <= high){
        int mid = (low+high)>>1;
        if(mid*mid < i)low= mid+1;
        else high = mid-1;
    }
    return low;
}

vector<int> AllPrimeFactors(int N) {
    vector<int>vec;
    for(int i = 2; i <= find_sqrt(N); ++i){
        if(N%i ==0){
            vec.push_back(i);
            while(N%i ==0){
                N/= i;
            }
        }
    }
    if(N != 1)vec.push_back(N);
    return vec;
}

int main(){
    vector<int>factors = AllPrimeFactors(100);
    for(auto i : factors)cout << i << " ";
    return 0;
}
