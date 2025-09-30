#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if(!root)return {};
    queue<TreeNode*>bfs;
    unordered_map<TreeNode*, TreeNode*>parent;
    unordered_map<TreeNode*, bool>visited;
    bfs.push(root);
    parent[root] = nullptr;
    while(!bfs.empty()){
        TreeNode* node = bfs.front();
        visited[node] = false;
        bfs.pop();
        if(node->left){
            bfs.push(node->left);
            parent[node->left] = node;
        }
        if(node->right){
            bfs.push(node->right);
            parent[node->right] = node;
        }
    }
    queue<TreeNode*>findingNodes;
    int distance = 0;
    findingNodes.push(target);
    visited[target] = true;
    while(distance <k){
        int n = findingNodes.size();
        for(int i = 0; i<n; i++){
            TreeNode* node = findingNodes.front();
            findingNodes.pop();
            if(parent[node] && !visited[parent[node]]){
                findingNodes.push(parent[node]);
                visited[parent[node]] = true;
            }
            if(node->left && !visited[node->left]){
                findingNodes.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right]){
                findingNodes.push(node->right);
                visited[node->right] = true;
            }
        }
        distance++;
    }
    vector<int>ans;
    while(!findingNodes.empty()){
        ans.push_back(findingNodes.front()->val);
        findingNodes.pop();
    }
    return ans;
}

