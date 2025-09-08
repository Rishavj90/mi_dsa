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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr)return true;
    if(p != nullptr && q != nullptr){
        bool l = isSameTree(p->left,q->left);
        bool r = isSameTree(p->right, q->right);
        if(l && r && p->val == q->val)return true;
    } 
    return false;
}