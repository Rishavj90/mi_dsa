#include <bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(long long int Arr[], long long int N) {
    long long int k = 0;
    for(auto i = 0; i < N; ++i){
        k = k^Arr[i];
    }
    long long int buc_1 = 0, buc_2 = 0, flag = (k&(k-1))^k;
    for(auto i = 0; i < N; ++i){
        if((Arr[i] & flag) == 0)buc_1= buc_1^Arr[i];
        else buc_2 = buc_2^Arr[i];
    }
    return{buc_1, buc_2};
}

int main(){
    long long int arr[] = {2,5,8,5,2,7,8,9};
    vector<long long int> ans = twoOddNum(arr,8);
    for(auto i : ans)cout << i << " ";
    return 0;
}