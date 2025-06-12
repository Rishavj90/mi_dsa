#include <bits/stdc++.h>
using namespace std;

int getXOR(int i){
    int a = i%4;
    switch (a){
    case 1: return 1;
    case 2: return i+1;
    case 3 : return 0; 
    }
    return i;
}

int findXOR(int l, int r) {
    int a = getXOR(l-1), b = getXOR(r);
    int ans = a ^b ;
    return ans;
}

int main(){
    cout << findXOR(1,10);
    return 0;
}