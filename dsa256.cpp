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

void findHt(TreeNode* root, int&hgt, int dir){
    if(!root)return;
    // 1: left, 2: right
    if(dir == 1)findHt(root->left, hgt, dir);
    else findHt(root->right, hgt, dir);
    hgt++;
}

int countNodes(TreeNode* root) {
    if(!root) return 0;

    // 1: left, 2: right
    int lh = 0;
    findHt(root, lh, 1);
    int rh = 0;
    findHt(root, rh, 2);

    if(lh == rh) return (1<<lh)-1;

    return 1+ countNodes(root->left)+ countNodes(root->right);
}