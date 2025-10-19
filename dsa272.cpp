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

//represents an iterator over the in-order traversal of BST
class BSTIterator {
    stack<TreeNode*>stk;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            stk.push(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        TreeNode* curr = stk.top();
        int ans = curr->val;
        stk.pop();
        curr = curr->right;
        while(curr){
            stk.push(curr);
            curr = curr->left;
        }
        return ans;
    }
    
    bool hasNext() {
        if(!stk.empty())return true;
        else return false;
    }
};

