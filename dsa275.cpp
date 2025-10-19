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

void helper(TreeNode* root, TreeNode* &prev, vector<TreeNode*>&vec){
    if(!root)return;
    helper(root->left, prev, vec);
    if(prev && root->val < prev->val){
        vec.push_back(prev);
        vec.push_back(root);
    }
    prev = root;
    helper(root->right, prev, vec);
}

void recoverTree(TreeNode* root) {
    vector<TreeNode*> vec;
    TreeNode* prev = nullptr;
    helper(root, prev, vec);
    swap(vec[0]->val, vec[vec.size()-1]->val);
    return ;
}

