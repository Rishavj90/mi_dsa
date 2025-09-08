#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void bfs(Node *root,map<int,int>&mpp){
    if(!root)return;
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    while(!q.empty()){
        int n= q.size();
        for(int i = 0; i< n; i++){
            Node* node = q.front().first;
            int col = q.front().second;
            if(mpp.find(col) == mpp.end()){
                mpp[col] = node->data;
            }
            if(node->left)q.push({node->left, col-1});
            if(node->right)q.push({node->right, col+1});
            q.pop();
        }
    }
}

vector<int> topView(Node *root) {
    map<int, int>mpp;
    bfs(root, mpp);
    vector<int>ans;
    for(auto i : mpp){
        ans.push_back(i.second);
    }
    return ans;
}