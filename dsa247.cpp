#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void bfs(Node* root, map<int,int>&mpp){
    if(!root)return;
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    while(!q.empty()){
        Node* node = q.front().first;
        if(node){
            int column = q.front().second;
            mpp[column] = node->data;
            q.push({node->left, column-1});
            q.push({node->right, column+1});
        }
        q.pop();
    }
}

vector<int> bottomView(Node *root) {
    map<int, int>mpp;
    int column = 0;
    bfs(root, mpp);
    vector<int>ans;
    for(auto i : mpp){
        ans.push_back(i.second);
    }
    return ans;
}