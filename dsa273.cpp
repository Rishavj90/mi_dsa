#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


void helper_successor(Node* root, int &key, Node* &next){
    if(!root)return;
    if(root->data <= key){
        helper_successor(root->right, key, next);
    }else{
        next = root;
        helper_successor(root->left, key, next);
    }
    return;
}

void helper_predecessor(Node* root, int &key, Node* &prev){
    if(!root)return;
    if(root->data >= key){
        helper_predecessor(root->left, key, prev);
    }else{
        prev = root;
        helper_predecessor(root->right, key, prev);
    }
    return;
}

vector<Node*> findPreSuc(Node* root, int key) {
    Node* next = nullptr, *prev = nullptr;
    helper_successor(root, key,next);
    helper_predecessor(root, key,prev);
    return {prev, next};
}
