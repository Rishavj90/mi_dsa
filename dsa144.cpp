#include <bits/stdc++.h>
using namespace std;

string decimal2Binary(int n){
    string str;
    while(n > 0){
        int b = n%2;
        char dig = '0'+b;
        str+= dig;
        n /= 2;    
    }
    reverse(str.begin(), str.end());
    return str;
}

bool checkKthBit(int n, int k) {
    int num = n >> k;
    if((num & 1) == 1)return true; //it is set
    return false; //it isn't set
}

/* another approach
bool checkKthBit(int n, int k) {
    int num = n >> k;
    if((num | 1) == num)return true; //it is set
    return false; //it isn't set
}*/

int main(){
    int a = 136;
    string bin = decimal2Binary(a);
    cout << bin << endl;
    cout << true << " : True " << false << " : false" << endl;
    cout << checkKthBit(a, 3);
    return 0;
}