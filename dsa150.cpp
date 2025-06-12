#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int num = 0;
    for(auto i : nums)num = (num^i);
    return num;
}
int main(){
    vector<int>nums = {2,3,4,1,2,3,4};
    cout << singleNumber(nums);
    return 0;
}