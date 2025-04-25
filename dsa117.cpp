#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node* merge_twoLL(Node* first, Node* second){
    Node* dmy = new Node(-1);
    Node* i = first, *j = second, *k = dmy;
    while(i != nullptr && j != nullptr){
        if(i->data < j->data){
            k->bottom = i;
            k = k->bottom;
            i = i->bottom;
        }else{
            k->bottom = j;
            k = k->bottom;
            j = j->bottom;
        }
        k->next = nullptr;
    }
    if(i != nullptr)k->bottom = i;
    else k->bottom = j;
    if(dmy->bottom != nullptr) dmy->bottom->next = nullptr;
    return dmy->bottom; 
}
Node* recur_flatten(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* second_LL = recur_flatten(head->next);
    Node* sorted_LL = merge_twoLL(head, second_LL);
    return sorted_LL;
}
Node *flatten(Node *root) {
    return recur_flatten(root);
}