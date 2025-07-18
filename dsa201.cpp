#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    for(int i = n-1; i >= 0; i--){
        int parent = (i-1)/2;
        if(arr[i] > arr[parent])return false;
    }
    return true;
}

int main(){
    int arr[] = {90, 15, 10, 7, 12, 2};
    cout << isMaxHeap(arr, 6);
    return 0;
}