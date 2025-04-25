#include <bits/stdc++.h>
using namespace std;

void selection_sort( vector<int> &arr){
    int s = arr.size();
    for(int i =0; i < s-1; i++){
        int min = INT_MAX;
        int k = 0;
        for(int j =i; j<s; j++){
            if(arr[j] < min){
                min = arr[j];
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
}

void bubble_sort( vector<int> &arr){
    int s = arr.size();
    for(int i = s-1; i >=0; i--){
        int didswap = 0;
        for(int j = 0; j < i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                didswap = 1;
            }
        }
        if(didswap==0){
            break;
        }
    }
}

void insertion_sort( vector<int> &arr){
    int s = arr.size();
    for(int i=1; i < s; i++){
        int j = i;
        while(j >0 && arr[j-1]>arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

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

void merge_sort(vector<int>& arr, int low, int high) {
    int n = arr.size();
    int mid = (low + high)/2;
    if(low == high) return;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    Merge(arr, low, mid, high);
}

//Quick Sort
int partindex(vector<int> &arr, int low, int high){
    int pivot = low;
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= arr[pivot] && i <= high-1) i++;
        while(arr[j] > arr[pivot] && j >= low+1) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    return j;
}

void quick_sort(vector<int> &arr, int low, int high){
    if(low >= high) return;
    int part = partindex(arr, low, high);
    swap(arr[low], arr[part]);
    quick_sort(arr, low, part-1);
    quick_sort(arr, part+1, high); 
}


int main(){
    vector<int>vec = {9,8,7,4,2,6,10,11,15,18,1};
    selection_sort(vec);
    for(auto i : vec){
        cout << i << " ";
    }
    return 0;
}