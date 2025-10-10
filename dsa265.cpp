#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int floor(Node* root, int x){
    if(!root)return -1;
    int ans = -1;
    while(root){
        if(root->data == x){
            ans = root->data;
            break;
        }
        if(root->data < x){
            ans = root->data;
            root= root->right;
        }else{
            root = root->left;
        }
    }
    return ans;
}

