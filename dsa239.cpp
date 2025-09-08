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

pair<int, bool> recSol(TreeNode* root){
    if(root == nullptr)return {0, true};
    pair<int, bool>a, b;
    a = recSol(root->left);
    b = recSol(root->right);
    if(a.second == true && b.second == true
       && abs(a.first - b.first)<=1
    )return {1+max(a.first, b.first), true};
    else return {1+max(a.first, b.first), false};
}

bool isBalanced(TreeNode* root) {
    if(recSol(root).second)return true;
    return false;
}