#include <bits/stdc++.h>
using namespace std;

int equalsOrSim(vector<vector<int>> &mat, int num){
    int r = mat.size();
    int c = mat[0].size();
    int ans = 0;
    for(int i =0; i < r; i++){
        int low = 0, high = c-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(mat[i][mid] > num){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        ans+= high+1;
    }
    return ans;
}

int median(vector<vector<int>> &mat) {
    int r = mat.size();
    int c = mat[0].size();
    int flag = (r*c)/2 + 1;
    int low = INT_MAX, high = INT_MIN;
    for(int i = 0; i < mat.size(); i++){
        if(low > mat[i][0]){
            low = mat[i][0];
        }
        if( high < mat[i][c-1]){
            high = mat[i][c-1];
        }
    }
    while(low <= high){
        int mid = low + (high-low)/2;
        int req = equalsOrSim(mat, mid);
        if(req <flag){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}

int main(){
    vector<vector<int>> vec = {{3},{5},{8}};
    cout << median(vec);
    return 0;
}