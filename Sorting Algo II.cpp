#include <bits/stdc++.h>
using namespace std;

void recursive_bubbleSort(vector<int> &vec, int k){
    if(k<=1) return;
    for(int i = 0; i < k-1; i++){
        if(vec[i] > vec[i+1]){
            swap(vec[i], vec[i+1]);
        }
    }
    return recursive_bubbleSort(vec, k-1);
}

void recursive_insertionSort(vector<int> &vec, int k){
    if(k <= 1) return;
    //get the sorted part
    recursive_insertionSort(vec, k-1);
    int key = vec[k-1];
    int i = k-2;
    while(i>= 0 && vec[i] > key){
        vec[i+1] = vec[i];
        i--;
    }
    vec[i+1] = key;
}

int main(){
    vector<int> vec = {6,2,7,4,9,1};
    //recursive_bubbleSort(vec, vec.size());
    recursive_insertionSort(vec, vec.size());
    for(auto i : vec){
        cout << i << " ";
    }
    return 0;
}