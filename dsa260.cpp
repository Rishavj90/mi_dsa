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

vector<int> MorrisInorder(TreeNode* root){
    vector<int>vec;

    TreeNode* currentNode = root;
    while(currentNode){
        if(!currentNode->left){
            vec.push_back(currentNode->val);
            currentNode = currentNode->right;
        }else{
            TreeNode* tmp = currentNode->left;
            while(tmp->right && tmp->right != currentNode){
                tmp = tmp->right;
            }
            if(!tmp->right){
                tmp->right = currentNode;
                currentNode = currentNode->left;
            }else{
                tmp->right = nullptr;
                vec.push_back(currentNode->val);
                currentNode = currentNode->right;
            }
                
        }
    }

    return vec; 
}

vector<int> inorderTraversal(TreeNode* root) {
    return MorrisInorder(root);
}