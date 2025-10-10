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

void helper(TreeNode* root, int &k, int &ans){
    if(!root)return;
    helper(root->left, k,ans);
    if(k>0){
        ans= root->val;
        k--;
    }
    else return;
    helper(root->right,k,ans);
}


int kthSmallest(TreeNode* root, int k) {
    int ans= 0;
    helper(root, k,ans);
    return ans;
}