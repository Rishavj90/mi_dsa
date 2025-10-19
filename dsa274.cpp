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

// bool helper(TreeNode* root, TreeNode* curr, int dif){
//     if(!root)return false;
//     if(root->val < dif)return helper(root->right, curr, dif);
//     else if(root->val > dif)return helper(root->left, curr,  dif);
//     else if(root == curr) return false;
//     return true;
// }

// bool findTarget(TreeNode* root, int k) {
//     queue<TreeNode*>q;
//     q.push(root);
//     while(!q.empty()){
//         int n  = q.size();
//         for(int i = 0; i < n; i++){
//             TreeNode* curr = q.front();
//             q.pop();
//             if(curr->val <= k && helper(root,curr,k - curr->val))return true;
//             if(curr->left)q.push(curr->left);
//             if(curr->right)q.push(curr->right);
//         }
//     }
//     return false;
// }

class traverse{
    private:
    stack<TreeNode*>ascending;
    stack<TreeNode*>descending;
    
    public:
    traverse(TreeNode* root){
        TreeNode* curr = root;
        while(curr){
            ascending.push(curr);
            curr = curr->left;
        }

        curr = root;
        while(curr){
            descending.push(curr);
            curr = curr->right;
        }
    }

    TreeNode* next(){
        TreeNode* ans;
        if(!ascending.empty())ans = ascending.top();
        else return nullptr;
        ascending.pop();
        TreeNode* curr = ans->right;
        while(curr){
            ascending.push(curr);
            curr = curr->left;
        }
        return ans;
    }

    TreeNode* back(){
        TreeNode* ans;
        if(!descending.empty())ans = descending.top();
        else return nullptr;
        descending.pop();
        TreeNode* curr = ans->left;
        while(curr){
            descending.push(curr);
            curr = curr->right;
        }
        return ans;
    }
};

bool findTarget(TreeNode* root, int k) {
    traverse itr(root);
    TreeNode* start = itr.next(), *end = itr.back();
    while(start && end && start != end && start->val < end->val){
        int sum = start->val + end->val;
        if(sum > k){
            end = itr.back();
        }else if(sum < k){
            start = itr.next();
        }else return true;
    }
    return false;
}


