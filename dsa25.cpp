#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    map<long long, int> pre_sum_mpp;
    long long sum = 0;
    int length = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        if(pre_sum_mpp.find(sum) == pre_sum_mpp.end()){
            pre_sum_mpp[sum] = i;
        }
        if(sum == k){
            length = max(length, i+1);
        }
        int rem = sum - k;
        if(pre_sum_mpp.find(rem) != pre_sum_mpp.end()){
            int len = i-pre_sum_mpp[rem];
            length = max(length, len);
        }
        
    }
    return length;
}


//Works great for positive number
// int longestSubarray(vector<int>& arr, int k) {
//     int sum = 0;
//     int maxlen = 0;
//     int j = 0;
//     for(int i = 0; i < arr.size(); i++){
//         sum += arr[i];
//         while(sum > k && j <= i){
//             sum -= arr[j];
//             j++;
//         }
//         if(sum == k){
//             maxlen = max(maxlen, i-j+1);
//         }
//     }
//     return maxlen;
// }

int main(){
    vector<int> vec = {94, -33, -13, 40, -82, 94, -33, -13, 40, -82};
    cout << longestSubarray(vec,52);
    return 0;
}