#include <bits/stdc++.h>
using namespace std;

/*
//brute force soln
int candy(vector<int>& ratings) {
    vector<int>left,right;
    left.push_back(1);
    right.resize(ratings.size(),1);
    int left_candy = 1, right_candy = 1, n = ratings.size();
    for(int i = 1; i < n; i++){
        if(ratings[i-1] < ratings[i])left_candy++;
        else left_candy=1;
        left.push_back(left_candy);

        if(ratings[n-i-1] > ratings[n-i])right_candy++;
        else right_candy=1;
        right[n-i-1] = right_candy;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans += max(left[i], right[i]);
    }
    return ans;
}
*/

//slope approach
int candy(vector<int>& ratings){
    int sum = 1, i = 1, n = ratings.size();
    while(i < n){
        if(ratings[i-1] == ratings[i]){
            sum++;
            i++;
            continue;
        }
        int peak = 1;
        while(i < n && ratings[i-1] < ratings[i]){
            peak++;
            sum+=peak;
            i++;
        }
        int down = 1;
        while(i < n && ratings[i-1] > ratings[i]){
            sum+=down;
            down++;
            i++;
        }
        if(down > peak)sum+=(down-peak);
    }
    return sum;
}

int main(){
    vector<int>rating = {1,0,2};
    cout << candy(rating);
    return 0;
}