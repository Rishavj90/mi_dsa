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

TreeNode* helper(int StartInorder, int EndInorder, vector<int>&inorder, int StartPreorder, int EndPreorder,vector<int>&preorder, unordered_map<int, int>&IndexMpp){
    if(StartInorder > EndInorder)return nullptr;
    TreeNode* root = new TreeNode(preorder[StartPreorder]);
    int index = IndexMpp[preorder[StartPreorder]];
    int leftSubTree = index - StartInorder;
    int rightSubTree = EndInorder - index;
    TreeNode* left = helper(StartInorder, index-1,inorder,StartPreorder+1, StartPreorder+leftSubTree, preorder,IndexMpp);
    TreeNode* right = helper(index+1, EndInorder, inorder, EndPreorder-rightSubTree+1, EndPreorder, preorder, IndexMpp);
    root->left = left;
    root->right = right;
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int>IndexMpp;
    for(int i = 0; i<inorder.size(); ++i){
        IndexMpp[inorder[i]] = i;
    }
    TreeNode* ans = helper(0,inorder.size()-1,inorder, 0, preorder.size()-1, preorder,IndexMpp);
    return ans;
}