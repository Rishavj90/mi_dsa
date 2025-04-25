#include <bits/stdc++.h>
using namespace std;

//check if sorted
// void Merge(vector<int> &arr, int low, int mid, int high){
//     vector<int> vec;
//     int left = low;
//     int right = mid+1;
//     while(left <= mid && right <= high){
//         if(arr[left] < arr[right]){
//             vec.push_back(arr[left]);
//             left++;
//         }else{
//             vec.push_back(arr[right]);
//             right++;
//         }
//     }
//     while(left<= mid){
//         vec.push_back(arr[left]);
//         left++;
//     }
//     while(right <= high){
//         vec.push_back(arr[right]);
//         right++;
//     }
//     for(int i = 0; i < vec.size(); i++){
//         arr[low+i] = vec[i];
//     }
// }
// void merge_sort(vector<int>&arr, int low, int high){
//     if(low == high) return;
//     int mid = (low + high)/2;
//     merge_sort(arr, low, mid);
//     merge_sort(arr, mid+1, high);
//     Merge(arr, low, mid, high);
// }

int main(){
    vector<int>nums = {3,4,5,1,2};
    int n = nums.size();
    for(int i = 0; i <n; i++){
        int flag = 1;
        int j = i+1;
        while(nums[j] == nums[i]){
            
        }
    }
    
    return 0;

}
