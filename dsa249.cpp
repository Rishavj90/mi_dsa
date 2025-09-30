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

bool isSame(TreeNode* left, TreeNode* right){
    if(!left && !right)return true;
    else if(left && right){
        bool a = isSame(left->left, right->right);
        bool b = isSame(left->right, right->left);
        if(a && b && left->val == right->val)return true;
    }
    return false;
}

bool isSymmetric(TreeNode* root) {
    return isSame(root->left, root->right);
}