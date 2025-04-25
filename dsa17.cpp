#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp;
    k %= n;
    if(k == 0) return;
    for(int i =0; i < n; i++){
        int a = nums[(n-k+i)%n];
        temp.push_back(a);
    }
    for(int i =0; i < n; i++){
        nums[i] = temp[i]; 
    }
    return;
}

int main(){
    vector<int> vec ={1,2,3,4,5,6,7};
    rotate(vec, 7);
    for(auto i : vec){
        cout << i << " ";
    }
    return 0;
}