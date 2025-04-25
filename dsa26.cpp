#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    set<int> unison;
    vector<int> temp;
    for(auto i : a) unison.insert(i);
    for(auto i : b) unison.insert(i);
    for(auto i : unison) temp.push_back(i);
    return temp;
}