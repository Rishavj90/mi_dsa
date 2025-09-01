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
int maxDepth(TreeNode* root) {
    stack<pair<TreeNode*, int>>stk;
    stk.push({root, 1});
    int ans = 0;
    while(!stk.empty()){
        TreeNode* node = stk.top().first;
        int level = stk.top().second;
        if(node != nullptr){
            stk.pop();
            stk.push({node->left, level+1});
            stk.push({node->right, level+1});
        }else{
            ans = max(ans, level-1);
            stk.pop();
        }
    }
    return ans;
}
*/


int maxDepth(TreeNode* root) {
    if(root == nullptr)return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l,r)+1;
}