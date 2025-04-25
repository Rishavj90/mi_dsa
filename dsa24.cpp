#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums){
    int count = 0;
    auto i = nums.begin();
    while(i != nums.end()){
        if(*i == 0) {
            count++;
            nums.erase(i);
        }else{
            i++;
        }   
    }
    for(int i = 0; i < count; i++){
        nums.push_back(0);
    }
}

int main(){
    vector<int> vec = {0};
    moveZeroes(vec);
    for(auto i : vec) cout << i << " ";
    return 0;
}