#include <bits/stdc++.h>
using namespace std;
//print n to 1 with backtracking

void print_num(int a, int b){
    if(a > b){
        return;
    }else{
        print_num(a+1,b);
        cout << a << " ";
    }
}

int main(){
    int a;
    cin >> a;
    print_num(1, a);
    return 0;
}
