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

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*>stk;
    vector<int>ans;
    stk.push(root);
    while(!stk.empty()){
        while(stk.top() != nullptr)stk.push(stk.top()->left);
        stk.pop();
        if(stk.empty())break;
        TreeNode* node = stk.top();
        ans.push_back(node->val);
        stk.pop();
        stk.push(node->right);
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int>ans = inorderTraversal(root);
    for(auto i : ans)cout << i << " ";
    return 0;
}