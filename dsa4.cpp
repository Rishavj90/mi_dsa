#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
    vector<int> com_gcd;
    int min;
    if( a>b){
        min = b;
    }else{
        min = a;
    }

    for(int i = 1; i <= min; ++i){
        if(a % i == 0 && b % i == 0){
            com_gcd.push_back(i);
        } 
    }
    
    int gcd = *max_element(com_gcd.begin(), com_gcd.end());
    return gcd;
}

int LCM(int a, int b){
    vector<int> com_lcm;
    int max, min;
    if( a>b){
        max = a;
        min = b;
    }else{
        max = b;
        min = a;
    }
    
    int fin = a*b;
    int i = 1;
    int num = max;
    while(num <= fin){
        if(num % min == 0){
            int lcm = num;
            return lcm;
        }
        i++;
        num = max*i;
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << GCD(a,b) << " "<< LCM(a,b);
    return 0;
}