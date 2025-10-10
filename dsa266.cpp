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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    TreeNode* curr = root;
    TreeNode* ans = root;
    while(curr){
        ans = curr;
        curr = (curr->val < val) ? curr = curr->right : curr = curr->left;
    }
    if(ans->val > val){
        ans->left = new TreeNode(val);
    }else{
        ans->right = new TreeNode(val);
    }
    return root;
}