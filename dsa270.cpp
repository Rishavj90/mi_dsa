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

TreeNode* helper(vector<int>& preorder, int start, int end){
    if(start == end)return nullptr;
    TreeNode* node = new TreeNode(preorder[start]);
    int tmp = start+1;
    while(tmp<end && preorder[tmp] < preorder[start])tmp++;
    node->left = helper(preorder, start+1, tmp);
    node->right = helper(preorder, tmp, end);
    return node;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int start = 0, end = preorder.size();
    return helper(preorder, start, end);
}
