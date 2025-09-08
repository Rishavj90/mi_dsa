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

int recSol(TreeNode* root, int &ans){
    if(root == nullptr)return 0;
    int l = max(0,recSol(root->left, ans));
    int r = max(0,recSol(root->right, ans));
    ans = max(ans, l+r+root->val);
    return root->val + max(l,r);
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    recSol(root, ans);
    return ans;
}

int main(){
    TreeNode* a = new TreeNode(2);
    a->left = new TreeNode(-1);
}