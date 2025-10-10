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

int findCeil(Node* root, int x) {
    Node* curr = root;
    if(!curr)return -1;
    int ans = INT_MAX;
    while(curr){
        if(curr->data < ans && curr->data >= x){
            ans = curr->data;
            if(curr->data == x)break;
        }
        curr = (curr->data > x) ? curr->left : curr->right;
    }
    if(ans == INT_MAX)ans = -1;
    return ans;
}