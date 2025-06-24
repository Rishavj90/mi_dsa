#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    vector<int>waterOnRoof(n,0);
    vector<int>maxLeft(n,0);
    vector<int>maxRight(n,0);

    int max_right = height[n-1];
    int max_left = height[0];
    for(int i = n-2; i >= 0; i--){
        maxRight[i] = max_right;
        max_right  = max(max_right, height[i]);
    }

    for(int i = 1; i < n; i++){
        maxLeft[i] = max_left;
        max_left = max(max_left, maxLeft[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int water = min(maxLeft[i],maxRight[i]) - height[i];
        if(water >= 0)waterOnRoof[i] = water;
        ans+= waterOnRoof[i];
    }
    return ans;
}

int main(){
    vector<int>height = {4,2,0,3,2,5};
    cout << trap(height);
    return 0;
}