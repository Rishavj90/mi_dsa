#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int trains = arr.size();
    int i =0, j=0;
    int cnt = 0, ans = 0;
    while(i<trains && j< trains){
        if(arr[i]<=dep[j]){
            cnt++;
            i++;
        }else{
            cnt--;
            j++;
        }
        ans = (cnt>ans)? cnt : ans;
    }
    return ans;
    
}