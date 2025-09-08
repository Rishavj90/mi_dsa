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

bool customComp(pair<int,int>&a, pair<int,int>&b){
    if(a.second == b.second)return a.first < b.first;
    return a.second < b.second;
}

void recSol(TreeNode* root, int row, int column, map<int, vector<pair<int,int>>>&mpp){
    if(!root)return;
    mpp[column].push_back({root->val, row});
    recSol(root->left,row+1,column-1,mpp);
    recSol(root->right, row+1,column+1,mpp);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    int row = 0, column = 0;
    map<int, vector<pair<int,int>>>mpp;
    //[column] = [{val, row}]
    recSol(root, row, column,mpp);
    vector<vector<int>>ans;
    for(auto i : mpp){
        sort(i.second.begin(), i.second.end(), customComp);
        vector<int>vec;
        for(auto j : i.second){
            vec.push_back(j.first);
        }
        ans.push_back(vec);
    }
    return ans;
}