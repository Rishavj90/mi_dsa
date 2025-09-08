#include <bits/stdc++.h>
using namespace std;

class Node {
public:
int data;
Node* left;
Node* right;

Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
}
};

bool isleaf(Node* root){
    if(root->left == nullptr && root->right == nullptr)return true;
    return false;
}

void leftNodes(Node* root, vector<int>&vec){
    if(root == nullptr)return;
    if(!isleaf(root))vec.push_back(root->data);
    if(root->left)leftNodes(root->left,vec);
    else leftNodes(root->right,vec); 
    return;
}

void leafNodes(Node* root, vector<int>&vec){
    if(root == nullptr)return;
    if(isleaf(root))vec.push_back(root->data);
    leafNodes(root->left,vec);
    leafNodes(root->right,vec);
}

void RevRightNodes(Node* root, vector<int>&vec){
    if(root == nullptr)return;
    if(root->right)RevRightNodes(root->right,vec);
    else RevRightNodes(root->left,vec);
    if(!isleaf(root))vec.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root) {
    if(!root) return {};
    vector<int>ans;
    if(!isleaf(root))ans.push_back(root->data);
    leftNodes(root->left, ans);
    leafNodes(root, ans);
    RevRightNodes(root->right, ans);
    return ans;
}

