#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() > 1){
        auto i = nums.begin();
        auto j = nums.begin()+1;
        while(i < nums.end() && j < nums.end()){
            if(*i != *j){
                i++;
                j++;
            }else{
                nums.erase(j);
            }
        }
    }
    return nums.size();
}

int main(){
    vector<int> vec = {0,1};
    cout << removeDuplicates(vec)<<endl;
    for(auto i : vec) cout << i << " ";
    return 0;
}