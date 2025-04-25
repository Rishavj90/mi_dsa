#include <bits/stdc++.h>
using namespace std;


int missingNumber(vector<int>& nums) {
    int n = nums.size();
    for(int i =0; i<=n; i++){
        auto it = find(nums.begin(), nums.end(), i);
        if(it == nums.end()) return i;
    }
}

int main(){
    vector<int> vec ={0};
    cout << missingNumber(vec);
    return 0;
}