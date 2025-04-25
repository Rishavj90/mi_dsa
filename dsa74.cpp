#include <bits/stdc++.h>
using namespace std;


vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int r = mat.size();
    int c = mat[0].size();
    int low = 0, high = c-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        int num = INT_MIN, max_flag = 0;
        for(int i = 0; i< r; i++){
            if(mat[i][mid] > num){
                num = mat[i][mid];
                max_flag = i;
            }
        }
        if(mid -1 >=0 && mat[max_flag][mid-1] >= mat[max_flag][mid]){
            high = mid-1;
        }else if(mid +1 <c && mat[max_flag][mid+1] >= mat[max_flag][mid]){
            low =  mid+1;
        }else{
            return {max_flag, low};
        }
    }
    return {-1};
}

int main(){
    vector<vector<int>> matrix = {{1,4}, {3,2}};
    vector<int> vec = findPeakGrid(matrix);
    for(auto i : vec){
        cout << i << " ";
    }
    return 0;
}