#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    int l = 0, r = 0;
    int maxFruits = 0;
    unordered_map<int, int>mpp;
    while(r < fruits.size()){
        if(mpp.find(fruits[r]) == mpp.end() && mpp.size() >= 2){
            l = mpp.begin()->second;
            int k;
            for(auto i : mpp){
                if(l >= i.second){
                    l = i.second;
                    k = i.first;
                }
            }
            l++;
            mpp.erase(k);
        }
        mpp[fruits[r]] = r;
        maxFruits = (r-l+1) > maxFruits ? (r-l+1) : maxFruits;
        r++;
    }
    return maxFruits;
}

int main(){
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout << totalFruit(fruits);
    return 0;
}