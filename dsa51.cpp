#include <bits/stdc++.h>
using namespace std;

//merge sort
void Merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = 0; i < temp.size(); i++){
        arr[low+i] = temp[i];
    }
    return;
}

int countReversePairs(vector<int> &arr, int low, int mid, int high){
    int cnt= 0;
    int right = mid+1;
    for(int i = low; i <= mid; i++){
        while(arr[i] > (long long)(2*arr[right]) && right <= high){
            right++;
        }
        cnt += right - (mid+1);
    }
    return cnt;
}


int merge_sort(vector<int>& arr, int low, int high) {
    int ans = 0;
    int mid = (low + high)/2;
    if(low == high) return 0;
    ans+= merge_sort(arr, low, mid);
    ans+= merge_sort(arr, mid+1, high);
    ans+= countReversePairs(arr, low, mid, high);
    Merge(arr, low, mid, high);
    return ans;
}

int reversePairs(vector<int>& nums) {
    return merge_sort(nums, 0, nums.size()-1);
}

int main(){
    vector<int> vec= {-5,-5};
    cout << reversePairs(vec);
    return 0;
}