#include <bits/stdc++.h>
using namespace std;
int nthRoot(int n, int m) {
    int low = 1, high = m;
    while(low<= high){
        int mid = (long long) (low+high)/2;
        int num = 1;
        for(int i = 0; i < n; i++){
            num*=mid;
        }
        if(num > m){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    int num = 1;
    for(int i = 0; i < n; i++){
        num*=high;
    }
    if(num != m){
        return -1;
    }
    return high;
}
int main(){
    cout << nthRoot(3,27);
    return 0;
}