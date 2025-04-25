#include <bits/stdc++.h>
using namespace std;

//O(4n) :(
void sortColors(vector<int>& nums){
    int n = nums.size();
    int count =0;
    vector<int> temp;
    int i = 0;
    while( i < 3){
        for(int j = 0; j < n; j++){
            if(nums[j] == i){
                count++;
            }
        }
        while(count>0){
            temp.push_back(i);
            count--;
        }
        i++;
    }
    for(int j = 0; j < n; j++){
        nums[j] = temp[j];
    }
    return;
}

int main(){
    vector<int> vec = {2,0,2,1,1,0};
    sortColors(vec);
    for(auto i : vec) cout <<i << " ";
    return 0;
}