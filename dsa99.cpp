#include <bits/stdc++.h>
using namespace std;

struct DLLNode{
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
DLLNode* vector_toDLL(vector<int>& vec){
    DLLNode* head = new DLLNode(vec[0]);
    DLLNode*mover = head;
    for(int i = 1; i < vec.size(); i++){
        DLLNode* temp = new DLLNode(vec[i]);
        temp->prev = mover;
        mover->next= temp;
        mover = mover->next;  
    }
    return head;
}

/*
DLLNode* reverseDLL(DLLNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    DLLNode* i = head;
    while(i->next != NULL){
        i = i->next;
    }
    head = i;
    while(i != NULL){
        DLLNode* temp = i->prev;
        i->prev = i->next;
        i->next = temp;
        i = i->next;
    }
    return head;
}
*/

DLLNode* reverseDLL(DLLNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    DLLNode* i = head;
    DLLNode* temp = NULL;
    while(i != NULL){
        temp = i->prev;
        i->prev = i->next;
        i->next = temp;
        i = i->prev;
    }
    return temp->prev;
}

int main(){
    vector<int> vec = {0,3,4,6,7,8};
    DLLNode* head = vector_toDLL(vec);
    head = reverseDLL(head);
    DLLNode* i = head;
    while(i != NULL){
        cout << i->data << " ";
        i = i->next;
    }
    return 0;
}