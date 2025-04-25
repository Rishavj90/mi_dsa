#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> presum;
    int sum = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        sum+= arr[i];
        if(sum == 0){
            ans = i+1;
        }else{
            if(presum.find(sum) == presum.end()){
                presum[sum] = i;
            }else{
                ans = max(ans, i - presum[sum]); 
            }
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {-31, -48, -90, 54, 20, 95, 6, -86, 22};
    cout << maxLen(vec);
    return 0;
}