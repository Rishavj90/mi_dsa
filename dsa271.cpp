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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* ans = nullptr;
    if(root->val > p->val && root->val > q->val)ans = lowestCommonAncestor(root->left, p,q);
    else if(root->val < p->val && root->val < q->val)ans = lowestCommonAncestor(root->right, p,q);
    else ans = root;
    return ans;
}

