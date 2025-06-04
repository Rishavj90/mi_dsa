#include <bits/stdc++.h>
using namespace std;

bool isEven(int n) {
    if((n & 1) == 0) return true;
    return false;
}

/* another approach
bool isEven(int n) {
    if((n | 1) == n ) return false; 
    return true;
}*/

int main(){
    cout << true << " : True " << false << " : false" << endl;
    cout << isEven(16);
    return 0;
}