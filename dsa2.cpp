#include <bits/stdc++.h>
using namespace std;

//Reverse a number

int main(){
    int x;
    cin >> x;

    vector<int> vec;
    int num;
    if(x < 0){
        num = x * (-1);
    }else{
        num = x;
    }
    while(num != 0){
        int digit = num % 10;
        vec.push_back(digit);
        num /= 10;
    }

    //printing the reverse number
    long long multiple = 1;
    for(int i =0; i < vec.size();++i){
        multiple *=10;
    }
    long long rnum = 0;
    for(int i =0; i < vec.size();++i){
        multiple /=10;
        rnum += vec[i]*multiple;
    }
    if(x < 0){
        rnum *= (-1);
    }

    cout << rnum;
    return 0;
}