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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*>q;
    vector<vector<int>>ans;
    if(root != nullptr)q.push(root);
    bool rightToLeft = false;
    while(!q.empty()){
        vector<int>vec;
        int n = q.size();
        vec.resize(n);
        for(int i = 0; i< n; i++){
            TreeNode* node = q.front();
            int j = (rightToLeft) ? (n-i-1) : i;
            vec[j] = node->val;
            q.pop();
            if(node->left != nullptr)q.push(node->left);
            if(node->right != nullptr)q.push(node->right);
        }
        rightToLeft = !rightToLeft;
        if(!vec.empty())ans.push_back(vec);
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>>ans = zigzagLevelOrder(root);
    for(auto i : ans){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}