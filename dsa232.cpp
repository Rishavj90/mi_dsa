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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* a = q.front();
            if(a != nullptr){
                level.push_back(a->val);
                q.push(a->left);
                q.push(a->right);
            }
            q.pop();
        }
        if(!level.empty())ans.push_back(level);
    }
    return ans;
}