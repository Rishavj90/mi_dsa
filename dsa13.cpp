#include <bits/stdc++.h>
using namespace std;

vector<int> frequencyCount(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    vector<int> freq(max+1, 0);
    for(int i = 0; i < arr.size(); ++i){
        freq[arr[i]]+=1;
    }
    return freq;
}

int main(){
    vector<int> arr = {3, 3, 3, 3};
    vector<int> new_arr = frequencyCount(arr);
    int n;
    cin >> n;
    cout << new_arr[n];
    return 0;
}