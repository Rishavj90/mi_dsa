#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int recSol(Node *root){
    if(!root)return 0;
    int l = recSol(root->left);
    int r = recSol(root->right);
    
    if(l == 0 && r == 0 && !root->left && !root->right)return root->data;
    if(l > -1 && r > -1 && root->data == (l+r))return root->data;
    return -1;
}

int isSumProperty(Node *root){
    if(recSol(root) != -1)return true;
    return false;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(10);
    
    cout << isSumProperty(root);
    return 0;
}