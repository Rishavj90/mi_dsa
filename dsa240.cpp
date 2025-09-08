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
int getHeight(TreeNode* root){
    if(root == nullptr)return -1;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return 1+max(l,r);
}

void recSol(TreeNode* root, int &ans){
    if(root == nullptr)return;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    ans = max(ans, l+r);
    recSol(root->left,ans);
    recSol(root->right,ans);
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    recSol(root, ans);
    return ans;
}*/

int recSol(TreeNode* root, int &ans){
    if(root == nullptr)return 0;
    int l = recSol(root->left, ans);
    int r = recSol(root->right, ans);
    ans = max(ans, l+r);
    return 1+max(l,r);
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    recSol(root, ans);
    return ans;
}
