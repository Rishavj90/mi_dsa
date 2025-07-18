#include <bits/stdc++.h>
using namespace std;

void convertMinToMaxHeap(vector<int> &arr, int N) {
    int i = N-1;
    while(i >= 0){
        int k = i;
        int l = 2*k+1, r = 2*k+2;
        while(l < N){
            if(r < N && arr[l] < arr[r] && arr[r] > arr[k]){
                swap(arr[r], arr[k]);
                k = r;
            }else{
                swap(arr[l], arr[k]);
                k = l;
            }
            l = 2*k+1, r = 2*k+2;
        }
        i--;
    }
    return;
}

int main(){
    vector<int> arr = {1,2,3,4};
    convertMinToMaxHeap(arr, arr.size());
    for(auto i : arr)cout << i << " ";
    return 0;
}
