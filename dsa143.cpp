#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    long long num = n;
    if(num==0)return false;
    if((num & (num-1)) == 0)return true;
    return false;
}

/* brute force
bool isPowerOfTwo(int n) {
    int low = 0, high = 100;
    while(low <= high){
        int mid = (low+high)>>1;
        long long num = (long long)1 << mid;
        if(num == n)return true;
        if(num > n) high = mid-1;
        else low = mid+1;
    }
    return false;
}
*/

int main(){
    cout << true << " : True " << false << " : false" << endl;
    cout << (0 & -1) << endl;
    cout << isPowerOfTwo(16);
    return 0;
}