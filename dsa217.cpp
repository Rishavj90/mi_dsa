#include <bits/stdc++.h>
using namespace std;

bool customComparator(pair<int,int>a, pair<int,int>b){
    double x = (double)a.first/a.second, y = (double)b.first/b.second;
    return x>y;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<pair<int,int>>vec;
    for(int i = 0; i< val.size();i++)vec.push_back({val[i],wt[i]});
    sort(vec.begin(),vec.end(),customComparator);

    int j = 0, mass = 0;
    double ans = 0;
    while(mass < capacity && j < val.size()){
        if((mass+vec[j].second) > capacity){
            ans += ((double)vec[j].first/vec[j].second)*(capacity-mass);
            mass += (capacity-mass);
        }else{
            ans += vec[j].first;
            mass += vec[j].second;
        }
        j++;
    }
    return ans;
}

int main(){
    vector<int>val = {8, 2, 10, 1, 9, 7, 2, 6, 4, 9};
    vector<int>wt = {10, 1, 7, 7, 5, 1, 8, 6, 8, 7};
    cout << fractionalKnapsack(val, wt,21);
    return 0;
}
