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


// void flatten(TreeNode* root){
//     TreeNode* current = root;

//     while(current){
//         if(current->left){
//             TreeNode* tail = current->left;
//             while(tail->right && tail->right != current->right){
//                 tail = tail->right;
//             }
//             if(!tail->right){
//                 tail->right = current->right;
//                 current->right = current->left;
//                 current->left = nullptr;
//             }
//         }
//         current = current->right;
//     }
// }

void helper(TreeNode* root, TreeNode* &prev){
    if(!root)return;
    helper(root->right, prev);
    helper(root->left, prev);
    root->right = prev;
    root->left = nullptr;
    prev = root;
}

void flatten(TreeNode* root){
    TreeNode* prev = nullptr;
    helper(root, prev);
}