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

vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*>stk;
    vector<int>ans;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* node = stk.top();
        stk.pop();
        if(node != nullptr){
            ans.push_back(node->val);
            stk.push(node->right);  //since it is stack, push right first
            stk.push(node->left);
        }
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int>ans = preorderTraversal(root);
    for(auto i : ans)cout << i << " ";
    return 0;
}