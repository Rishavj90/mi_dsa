#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//(size, min, max)
tuple<int, int, int> helper(Node* root){
    if(!root)return {0, INT_MAX, INT_MIN};
    tuple<int, int, int> l, r;

    auto [l_size, l_min, l_max] = helper(root->left);
    auto [r_size, r_min, r_max] = helper(root->right);

    if(l_max < root->data && r_min > root->data){
        int size = 1 + l_size + r_size;
        int minNum = min(root->data, l_min);
        int maxNum = max(root->data, r_max);
        return {size, minNum, maxNum};
    }
    return {max(l_size, r_size), INT_MIN, INT_MAX};

}

int largestBst(Node *root) {
    tuple<int, int, int> tpl = helper(root);
    return get<0>(tpl);
}

