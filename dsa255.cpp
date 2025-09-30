#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void parentAndVisitedMap(unordered_map<Node*, Node*>&mpp,unordered_map<Node*, bool>&Visited, Node*&_target, Node*root, int target){
    if(!root)return;
    queue<Node*>q;
    q.push(root);
    mpp[root] = nullptr;

    while(!q.empty()){
        Node* tmp = q.front();
        Visited[tmp] = false;
        if(tmp->data == target)_target = tmp;
        q.pop();
        if(tmp->left){
            q.push(tmp->left);
            mpp[tmp->left] = tmp;
        }
        if(tmp->right){
            q.push(tmp->right);
            mpp[tmp->right] = tmp;
        }
    }

}


int minTime(Node* root, int target) {
    unordered_map<Node*, bool>Visited;
    unordered_map<Node*, Node*>mpp;
    Node* _target = nullptr;
    parentAndVisitedMap(mpp, Visited, _target, root, target);

    int ans = 0;
    queue<pair<Node*, int>>q;
    q.push({_target, 0});
    Visited[_target] = true;
    while(!q.empty()){
        Node* tmp = q.front().first;
        int num = q.front().second;
        ans = max(num, ans);
        q.pop();
        if(mpp[tmp] && !Visited[mpp[tmp]]){
            q.push({mpp[tmp], num+1});
            Visited[mpp[tmp]] = true;
        }
        if(tmp->left && !Visited[tmp->left]){
            q.push({tmp->left, num+1});
            Visited[tmp->left] = true;
        }
        if(tmp->right && !Visited[tmp->right]){
            q.push({tmp->right, num+1});
            Visited[tmp->right] = true;
        }
        
    }
    return ans;

}