#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void recSol(Node* root, vector<int>vec, vector<vector<int>>&ans){
    if(!root)return;
    vec.push_back(root->data);
    if(root->left)recSol(root->left, vec, ans);
    if(root->right)recSol(root->right, vec, ans);
    if(!root->left && !root->right)ans.push_back(vec);
}

vector<vector<int>> Paths(Node* root) {
    vector<vector<int>>ans;
    vector<int>vec;
    recSol(root, vec, ans);
    return ans;
}