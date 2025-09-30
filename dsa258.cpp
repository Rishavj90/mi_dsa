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

TreeNode* helper(int StartInorder, int EndInorder, vector<int>& inorder, int StartPostorder, int EndPostorder,vector<int>& postorder, unordered_map<int, int>&IndexMpp){
    if(StartInorder > EndInorder)return nullptr;
    TreeNode* root = new TreeNode(postorder[EndPostorder]);
    int index = IndexMpp[postorder[EndPostorder]];
    int leftSubTree = index - StartInorder;
    int rightSubTree = EndInorder - index;
    TreeNode* left = helper(StartInorder, index-1, inorder, StartPostorder, StartPostorder+leftSubTree-1,postorder, IndexMpp);
    TreeNode* right = helper(index+1, EndInorder,inorder, StartPostorder+leftSubTree, EndPostorder-1, postorder, IndexMpp);
    root->left = left;
    root->right = right;
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int>IndexMpp;
    for(int i = 0; i<inorder.size(); ++i){
        IndexMpp[inorder[i]] = i;
    }
    TreeNode* ans = helper(0, inorder.size()-1,inorder, 0, postorder.size()-1, postorder, IndexMpp);
    return ans;
}