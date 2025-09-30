#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
bool traversal(TreeNode* root, TreeNode* p, stack<TreeNode*>&stk){
    if(!root)return false;
    if(root == p){
        stk.push(p);
        return true;
    }
    bool l = traversal(root->left, p, stk);
    bool r = traversal(root->right, p, stk);
    if(l||r){
        stk.push(root);
        return true;
    }
    return false;

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode*>p_stk, q_stk;
    TreeNode* ans = nullptr;
    traversal(root, p, p_stk);
    traversal(root, q, q_stk);
    while(!p_stk.empty() && !q_stk.empty() && p_stk.top() == q_stk.top()){
        ans = p_stk.top();
        p_stk.pop();
        q_stk.pop();
    }
    return ans;
}
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)return nullptr;
    if(root == p || root == q)return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left && right)return root;
    if(left)return left;
    if(right)return right;
    return nullptr;
}