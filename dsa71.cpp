#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k) {
    vector<int> nums1 = a;
    vector<int> nums2 = b;
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n1 > n2) return kthElement(nums2, nums1, k);
    int low = max(k-n2, 0), high = min(k, n1);
    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = k - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1 -1 >= 0) l1 = nums1[mid1-1];
        if(mid2 -1 >= 0) l2 = nums2[mid2-1];
        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }else if(l1 > r2){
            high = mid1-1;
        }else{
            low = mid1+1;
        }
    }
    return 0;
}

int main(){
    vector<int> vec1 = {2, 3, 6, 7, 9};
    vector<int> vec2 = {1, 4, 8, 10};
    cout << kthElement(vec1, vec2, 5);
    return 0;
}