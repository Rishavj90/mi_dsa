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

//using 1 stack
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*>stk;
    vector<int>ans;
    TreeNode* curr = root;
    while(!stk.empty() || curr != nullptr){
        if(curr != nullptr){
            stk.push(curr);
            curr = curr->left;
        }else{
            TreeNode* tmp = stk.top()->right;
            if(tmp == nullptr){
                tmp = stk.top();
                stk.pop();
                ans.push_back(tmp->val);
                while(!stk.empty() && tmp == stk.top()->right){
                    tmp = stk.top();
                    ans.push_back(tmp->val);
                    stk.pop();
                }
            }else{
                curr = tmp;
            }
        }
    }
    return ans;
}