#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int a = nums1.size();
    for(int i = 0; i < n; i++){
        nums1[m+i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
    return;
}
int main(){
    vector<int> vec1 = {1,2,4,5,6,0};
    vector<int> vec2 = {3};
    merge(vec1, 5,vec2,vec2.size());
    for(auto i : vec1){
        cout << i << " ";
    }
    return 0;
}