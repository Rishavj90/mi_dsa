#include <bits/stdc++.h>
using namespace std;

/*
//recursion
class Solution {
private:
bool recursion(int index, vector<int>& arr, int sum){
    if(index<=0){
        if(sum==0)return true;
        return (arr[index]==sum);
    }

    int option1=false;
    if(arr[index-1]<=sum)option1=recursion(index-1,arr,sum-arr[index-1]);

    int option2=false;
    option2=recursion(index-1,arr,sum);

    return option1||option2;

}

public:
bool isSubsetSum(vector<int>& arr, int sum) {
    return recursion(arr.size()-1, arr, sum);
}
};
*/

/*
class Solution {
public:
bool isSubsetSum(vector<int>& arr, int sum) {
    int n=arr.size();
    vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
    for(int i=0; i<n; i++)dp[i][0]=true;
    dp[0][arr[0]]=true;

    for(int i=1; i<n; i++){
        for(int j=0; j<=sum; j++){
            bool notTake=dp[i-1][j];
            bool take=false;
            if(j>=arr[i])take=dp[i-1][j-arr[i]];
            dp[i][j]=take|notTake;
        }
    }
    return dp[n-1][sum];
}
};
*/

class Solution {
public:
bool isSubsetSum(vector<int>& arr, int sum) {
    int n=arr.size();
    vector<bool>dp(sum+1,false);
    dp[0]=true;
    dp[arr[0]]=true;

    for(int i=1; i<n; i++){
        vector<bool>tmp(sum+1,false);
        tmp[0]=true;
        for(int j=1; j<=sum; j++){
            bool notTake=dp[j];
            bool take=false;
            if(j>=arr[i])take=dp[j-arr[i]];
            tmp[j]=take|notTake;
        }
        dp=tmp;
    }
    return dp[sum];
    
}
};

