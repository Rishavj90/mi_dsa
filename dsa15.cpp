#include <bits/stdc++.h>
using namespace std;
int getSecondLargest(vector<int> &arr);

//Second largest element in array
int main(){
    vector<int> vec = {10, 8, 10};
    cout << getSecondLargest(vec);
}

int getSecondLargest(vector<int> &arr) {
    int max = INT_MIN, next_max = INT_MIN;
    for(auto i : arr){
        if(i > max){
            next_max = max;
            max = i;
        }else if(i > next_max && i != max)next_max = i;
    }
    if(next_max == INT_MIN){
        next_max = max;
    }
    return next_max;
}