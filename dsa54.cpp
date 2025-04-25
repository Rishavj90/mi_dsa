#include <bits/stdc++.h>
using namespace std;
vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    int flr = -1, cl = -1;
    int low = 0, high = arr.size()-1;
    sort(arr.begin(), arr.end());
    while(low<= high){
        int mid = (low+high)/2;
        if(arr[mid]<= x){
            flr = arr[mid];
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    low = 0, high = arr.size()-1;
    while(low<= high){
        int mid = (low+high)/2;
        if(arr[mid] >= x){
            cl = arr[mid];
            high = mid -1;
        }else{
            low = mid+1;
        }
    }
    return {flr, cl};
}

int main(){
    vector<int> vec = {5, 6, 8, 8, 6, 5, 5, 6};
    vector<int> ans = getFloorAndCeil(10, vec);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}