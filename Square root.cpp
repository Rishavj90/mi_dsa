#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int low = 1, high = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        int sqr = (long long)mid*mid;
        if(sqr > n){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return high;
}
int main(){
    cout << floorSqrt(36);
    return 0;
}