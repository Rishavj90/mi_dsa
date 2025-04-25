#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x) { data = x; next = prev = NULL; }
};
Node* vector_toDLL(vector<int>& vec){
    if(vec.size() == 0) return nullptr;
    Node* head = new Node(vec[0]);
    Node*mover = head;
    for(int i = 1; i < vec.size(); i++){
        Node* temp = new Node(vec[i]);
        temp->prev = mover;
        mover->next= temp;
        mover = mover->next;  
    }
    return head;
}

/*  works even for unsorted input
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    vector<pair<int, int>> vec;
    Node* i = head;
    while(i != nullptr){
        Node* j = i->prev;
        while(j != nullptr){
            if(j->data == (target - i->data)){
                vec.push_back({i->data, j->data}); 
                break;
            }
            j = j->prev;
        }
        i = i->next;
    }
    return vec;
}
*/

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    if(head == nullptr) return {};
    vector<pair<int, int>> vec;
    Node* i = head;
    while(i->next != nullptr){
        i = i->next;
    }
    Node* left = head;
    Node* right = i;
    while(left->data < right->data){
        int l = left->data, r = right->data;
        if(left->data + right->data > target) right = right->prev;
        else if(left->data + right->data < target) left = left->next;
        else{
            vec.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
    } 
    return vec;
}

int main(){
    vector<int> vec = {1,2,3,4};
    Node* head = vector_toDLL(vec);
    vector<pair<int, int>> vec2 = findPairsWithGivenSum(head, 5);
    for(auto i : vec2){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}