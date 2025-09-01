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

//Time Complexity : O(3n)
//Space Complexity : O(3n)
vector<vector<int>> Traversals(TreeNode* root){
    stack<pair<TreeNode*, int>>stk;
    stk.push({root, 1});
    vector<int>order;
    vector<vector<int>>ans(3, order);

    while(!stk.empty()){
        TreeNode* node = stk.top().first;
        int num = stk.top().second;
        if(node != nullptr){
            if(num == 1){
                ans[0].push_back(node->val);  //preOrder Traversal
                stk.pop();
                stk.push({node, ++num});
                if(node->left != nullptr)stk.push({node->left, 1});
            }else if(num == 2){
                ans[1].push_back(node->val);  //InOrder Traversal
                stk.pop();
                stk.push({node, ++num});
                if(node->right != nullptr)stk.push({node->right, 1});
            }else{
                ans[2].push_back(node->val);  //PostOrder Traversal
                stk.pop();
            }
        }else stk.pop();

    }
    return ans;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<vector<int>>ans = Traversals(root);
    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}