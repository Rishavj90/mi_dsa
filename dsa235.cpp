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

vector<int> postorderTraversal(TreeNode* root) {
    vector<int>ans;
    stack<TreeNode*>stk;
    stack<int>ansStk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* node = stk.top();
        if(node != nullptr){
            ansStk.push(node->val);
            stk.pop();
            stk.push(node->left);
            stk.push(node->right);
        }else stk.pop();
    }
    while(!ansStk.empty()){
        ans.push_back(ansStk.top());
        ansStk.pop();
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int>ans = postorderTraversal(root);
    for(auto i : ans)cout << i << " ";
    return 0;
}