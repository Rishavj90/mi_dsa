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
bool helper(TreeNode* root, long &curr, long &prev){
    if(!root)return true;
    bool left = helper(root->left, curr, prev);
    if(!left)return false;
    curr = root->val;
    if(curr <= prev)return false;
    prev = curr;
    bool right = helper(root->right,curr, prev);
    if(!right)return false;
    return true;
}

bool isValidBST(TreeNode* root) {
    long curr = 1, prev = LONG_MIN;
    return helper(root, curr, prev);
}
*/

bool helper(TreeNode* root, long min, long max){
    if(!root)return true;
    if(root->val <= min || root->val >= max)return false;
    bool left = helper(root->left, min, root->val);
    if(!left)return false;
    bool right = helper(root->right, root->val, max);
    if(!right)return false;
    return true;
}

bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}
