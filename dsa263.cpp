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

int findMax(Node *root) {
    while(root && root->right)root = root->right;
    return root->data;
}

int findMin(Node *root) {
    while(root && root->left)root = root->left;
    return root->data;
}