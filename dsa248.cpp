#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
void bfs(TreeNode* root, map<int,int>&mpp){
    if(!root)return;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    while(!q.empty()){
        TreeNode* node = q.front().first;
        if(node){
            int row = q.front().second;
            mpp[row] = node->val;
            q.push({node->left, row+1});
            q.push({node->right, row+1});
        }
        q.pop();
    }
}

vector<int> rightSideView(TreeNode* root) {
    map<int, int>mpp;
    int column = 0;
    bfs(root, mpp);
    vector<int>ans;
    for(auto i : mpp){
        ans.push_back(i.second);
    }
    return ans;
}
*/

void recSol(TreeNode* root,int row, vector<int>&ans){
    if(!root)return;
    if(row == ans.size())ans.push_back(root->val);
    recSol(root->right, row+1, ans);
    recSol(root->left, row+1, ans);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int>ans;
    recSol(root, 0, ans);
    return ans;
}
