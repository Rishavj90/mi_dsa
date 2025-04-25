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

Node* deleteNode(Node* head, int x) {
    if(head == NULL){
        return NULL;
    }else if(head->next == NULL){
        delete head;
        return NULL;
    }
    int count = 0; 
    Node* front = NULL, *back = NULL;
    Node* i = head;
    while(i != NULL){
        count++;
        if(count == x){
            front = i->next;
            back = i->prev;
            break;
        }
        i = i->next;
    }
    if(front == NULL && back == NULL){
        return head;
    }
    //header node
    if(back == NULL){
        front->prev = NULL;
        head = i->next;
    }//end node
    else if(front == NULL){
        back->next = NULL;
        back = NULL;
    }else{
        back->next = front;
        front->prev = back;
        front = NULL, back = NULL;
    }
    delete i;
    return head;
}


int main(){
    vector<int> vec = {0,3,4,6,7,8};
    Node* head = vector_toDLL(vec);
    head = deleteNode(head, 3);
    Node* i = head;
    while(i != NULL){
        cout << i->data << " ";
        i = i->next;
    }
    return 0;
}