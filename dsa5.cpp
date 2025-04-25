#include <bits/stdc++.h>
using namespace std;

// check if it is an Armstrong number
int main(){
    int a;
    cin >> a;
    
    int num = a;
    vector<int> vec;
    int digit;
    while(num != 0){
        digit = num%10;
        vec.push_back(digit);
        num/=10;
    }

    int check = 0;
    for(int i = 0; i <vec.size(); ++i){
        int num2 = 1;
        for(int j = 0; j < vec.size(); ++j){
            num2 = vec[i]*num2;
        }
        check+=num2;
    }

    if(a== check){
        cout << "YESS!";
    }else{
        cout << "nahh!";
    }

    return 0;
} 