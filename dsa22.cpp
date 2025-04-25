#include <bits/stdc++.h>
using namespace std;

// into binary
vector<int> intoBinary(int num){
    vector<int> bi;
    while(num != 0){
        int a = num%2;
        bi.push_back(a);
        num/=2;
    }
    int n = bi.size();
    for(int i = 0; i < n/2; ++i){
        swap(bi[i], bi[n-1-i]);
    }
    return bi;
}

//into decimal from binary
int intoDecimal(vector<int>& arr){
    int n = arr.size();
    int div = 1;
    int num = 0;
    for(int i = n-1; i>= 0; i--){
        num += div*arr[i];
        div*=2;
    }
    return num;
}

int main(){
    vector<int> vec = {1,1,0,0,1};
    int num = 14;
    vector<int> binary = intoBinary(num);
    int decimal = intoDecimal(vec);
    for(auto i : binary) cout << i;
    cout <<" "<<decimal;
    return 0;
}