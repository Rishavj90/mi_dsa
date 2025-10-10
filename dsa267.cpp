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


TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root)return nullptr;
    TreeNode* curr = root, *node = root;
    bool foundNode = false;
    while(curr){
        if(curr->val == key){
            foundNode = true;
            break;
        }
        node = curr;
        curr = (curr->val < key) ? curr->right : curr->left;
    }
    if(foundNode){
        if(node == curr){
            helper(root, curr);
        }else{
            if(node->left == curr)helper(node->left, curr);
            else helper(node->right, curr);
        }
    }
    return root;
}

void helper(TreeNode* &node, TreeNode* &curr){
    if(curr->left){
        node = curr->left;
        if(curr->right){
            TreeNode* tmp = curr->left;
            while(tmp->right)tmp = tmp->right;
            tmp->right = curr->right;
        }
    }else if(curr->right){
        node = curr->right;
    }else{
        node = nullptr;
    }
    delete curr;
}

