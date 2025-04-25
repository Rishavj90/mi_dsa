#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums){
    vector<int> temp;
    int check = 0;
    for(auto i : nums){
        if(i == 1) check++;
        else{
            temp.push_back(check);
            check = 0;
        }
    }
    temp.push_back(check);
    int max = *max_element(temp.begin(), temp.end());
    return max;
}
int main(){
    vector<int> vec1 ={1,0,1,1,0,1};
    cout << endl<< findMaxConsecutiveOnes(vec1);
}