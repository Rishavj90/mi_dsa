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

/*
string serialize(TreeNode* root) {
    if(!root) return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode* helper(int &i, string &data){
    if(data[i] == '#'){
        i+=2;
        return nullptr;
    }
    int num = 0;
    bool pos = true;
    if(data[i] == '-'){
        pos = !pos;
        i++;
    }
    while(i< data.size() && data[i]!= '#' && data[i] != ','){
        num *= 10;
        num += (data[i] - '0');
        i++;
    }
    if(!pos)num = -num;
    i++;

    TreeNode* root = new TreeNode(num);
    TreeNode* left = helper(i, data);
    TreeNode* right = helper(i, data);
    
    root->left = left;
    root->right = right;
    return root;
}

TreeNode* deserialize(string data) {
    int i = 0;
    return helper(i, data);
}
*/

