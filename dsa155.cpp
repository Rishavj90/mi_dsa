#include <bits/stdc++.h>
using namespace std;

int find_sqrt(int i){
    int low = 0, high = i;
    while(low <= high){
        int mid = (low+high)>>1;
        if(mid*mid < i)low= mid+1;
        else high = mid-1;
    }
    return low;
}

void print_divisors(int n) {
    set<int>vec;
    int k = find_sqrt(n);
    for(int i = 1; i <= k; ++i){
        if(n%i ==0){
            vec.insert(i);
            if(i != (n/i))vec.insert(n/i);
        }
    }
    for(auto a : vec)cout<< a << " ";
    return;
}

int main(){
    print_divisors(20);
    return 0;
}