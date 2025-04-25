#include <bits/stdc++.h>
using namespace std;

//select the smallest and second smallest numbers and add them
int pairWithMaxSum(vector<int> &arr){
    int n = arr.size();
    int score = 0;
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        sum = arr[i]+arr[i+1];
        score = max(score, sum);
    }
    return score;
}

int main(){
    vector<int> vec = {642, 216, 187, 135, 28, 706, 661, 353, 890, 890};
    cout << pairWithMaxSum(vec);
    return 0;
}