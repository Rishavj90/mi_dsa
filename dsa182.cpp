#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<pair<int, int>>stk;  //{height, index}
    int max_area = INT_MIN;
    for(int i = 0; i < heights.size(); i++){
        int index = i;
        while(!stk.empty() && stk.top().first >= heights[i]){
            int ht = stk.top().first;
            index = stk.top().second;
            int area = ht*(i - index );
            max_area = area > max_area ? area : max_area;
            stk.pop();
        }
        stk.push({heights[i], index});
    }
    while(!stk.empty()){
        int ht = stk.top().first;
        int index = stk.top().second;
        int area = ht*(heights.size()- index);
        max_area = area > max_area ? area : max_area;
        stk.pop();
    }
    return max_area;
}

int main(){
    vector<int>heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights);
    return 0;
}