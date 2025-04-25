#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;

    int num =0;
    for(int i =1; i <= a; ++i){
        for(int j = 1; j <= i; ++j){
            if(i % j == 0){
                num+=j;
            }
        }
    }

    cout << num;
    return 0;
}