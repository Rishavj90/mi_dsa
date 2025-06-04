#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
   vector<int>cnt;
    for(int i = 0; i <= n; ++i){
        int k = i, count = 0;
        while(k != 0){
            count++;
            k = k & (k-1);  //turns off the rightmost set bit
        }
        cnt.push_back(count);
    }
    return cnt; 
}

/* Mathod 1
vector<int> countBits(int n) {
    vector<int>cnt;
    for(int i = 0; i <= n; ++i){
        int k = i, count = 0;
        while(k != 0){
            count+=(k & 1);
            k = k >> 1;
        }
        cnt.push_back(count);
    }
    return cnt;
}
*/

int main(){
    vector<int> vec = countBits(15);
    for(auto i : vec)cout << i << " ";
    return 0;
}