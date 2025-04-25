#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};
Node* vector_toDLL(vector<int>& vec){
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

Node *addNode(Node *head, int pos, int data) {
    Node* new_node = new Node(data);
    if(head == NULL){
        return new_node;
    }
    if(pos == 0){
        new_node->next = head;
        head->prev = new_node;
        return new_node;
    }
    int count = -1;
    Node* i = head;
    Node* front = NULL, *back = NULL;
    while(i != NULL){
        count++;
        if(count == pos){
            front = i->next;
            back = i;
            break;
        }
        i= i->next;
    }
    if(front == NULL && back == NULL){
        return head;
    }
    if(front != NULL){
        new_node->next = front;
        new_node->prev = back;
        back->next= new_node;
        front->prev = new_node;
    }else{
        back->next = new_node;
        new_node->prev = back;
    }
    return head;
}

int main(){
    vector<int> vec = {0,3,4,6,7,8};
    Node* head = vector_toDLL(vec);
    head = addNode(head, 2, 18);
    Node* i = head;
    while(i != NULL){
        cout << i->data << " ";
        i = i->next;
    }
    return 0;
}