#include <bits/stdc++.h>
using namespace std;

vector<int> hashh(vector<int> &arr){
    int max = *max_element(arr.begin(), arr.end());
    vector<int> hsh(max+1, 0);
    for(int i = 0; i < arr.size();++i){
        hsh[arr[i]]++;
    }
    return hsh;
}
int main(){
    vector<int> vec = {10,5,10,15,10,5};
    vector<int> vec_hsh = hashh(vec);
    int max_freq = *max_element(vec_hsh.begin(), vec_hsh.end());
    for(int i = 0; i < vec_hsh.size(); i++){
        if(vec_hsh[i] == max_freq){
            cout << i << " ";
        }
    }
    int min_freq = INT_MAX;
    for(int i = 0; i < vec_hsh.size(); i++){
        if(vec_hsh[i] > 0 && vec_hsh[i] < min_freq){
            min_freq = vec_hsh[i];
        }
    }

    for(int i = 0; i < vec_hsh.size(); i++){
        if(vec_hsh[i] == min_freq){
            cout << i << " ";
        }
    }

}