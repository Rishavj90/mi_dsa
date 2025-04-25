#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size()-1;
    while(low <=high){
        int mid = low + (high - low)/2;
        int missing_nums = arr[mid] - (mid+1);
        if(missing_nums < k){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return k + (high + 1);
}
int main(){
    vector<int> vec = {1,2,3,4};
    cout << findKthPositive(vec,2);
    return 0;
}