#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &arr) {
    int r = arr.size();
    int c = arr[0].size();
    int index_1 = INT_MAX, ans;
    for(int i = 0; i < r; i++){
        int low = 0, high = c-1;
        while(low <= high){
            int mid = (low+ high)/2;
            if(arr[i][mid] == 0){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        if(index_1 > low){
            index_1 = low;
            ans = i;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> vec = {{0,1,1,1},{0,0,1,1},{1,1,1,1},{0,0,0,0}};
    cout << rowWithMax1s(vec);
    return 0;
}