#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if(!root)return 0;
    queue<pair<TreeNode*, long>>q;
    q.push({root, 0});
    int maxWidth = 0;
    while(!q.empty()){
        int n = q.size();
        long minNum = q.front().second;
        int first, last;
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front().first;
            long tag = q.front().second - minNum;
            q.pop();
            if(i == 0) first = tag;
            if(i == n-1) last = tag;
            if(node->left)q.push({node->left, 2*tag+1});
            if(node->right)q.push({node->right, 2*tag+2});
        }
        maxWidth= max(maxWidth, last-first+1);
    }
    return maxWidth;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    cout << widthOfBinaryTree(root);
}