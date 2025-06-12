#include <bits/stdc++.h>
using namespace std;

string int_2_str(int n){
    string str;
    while(n != 0){
        str += ('0' + (n%10));
        n /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

void XOR_triangle(int n){
    string str = "1";
    int k = 1;
    cout << "N : 1   0 ^ 1 = 1" << endl;
    for(int i = 2; i<= n; ++i){
        k = k^i;
        str = str + " ^ " + int_2_str(i);
        cout << "N : " << i << "   " << str << " = " << k << endl;
    }
}

int main(){
    XOR_triangle(50);
    return 0;
}