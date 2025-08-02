#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for(auto i: bills){
        if(i == 5){
            five++;
        }else if(i == 10){
            ten++;
            if(five>0)five--;
            else return false;
        }else{
            if(ten>0 && five>0){
                ten--;
                five--;
            }else if(five>=3){
                five-=3;
            }else return false;
        }
    }
    return true;
}

int main(){
    vector<int>bills = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    cout << lemonadeChange(bills);
    return 0;
}