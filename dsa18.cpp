#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> temp;
    for(auto i : a){
        auto ptr = find(temp.begin(), temp.end(), i);
        if(ptr == temp.end()) temp.push_back(i);
    }
    for(auto i : b){
        auto ptr = find(temp.begin(), temp.end(), i);
        if(ptr == temp.end()) temp.push_back(i);
    }
    
    //selection sort
    for(int i = 0; i < temp.size()-1; i++){
        int min = INT_MAX;
        int k = 0;
        for(int j = i; j < temp.size(); j++){
            if(temp[j] < min){
                min = temp[j];
                k = j;
            }
        }
        swap(temp[i], temp[k]);
    }
    return temp; 
}


int main(){
    vector<int> vec1 ={1, 2, 3, 4, 5};
    vector<int> vec2 ={1, 2, 3, 6, 7};
    vector<int> vec3 =findUnion(vec1, vec2);
    for(auto i :vec3) cout << i << " ";
    return 0;
}