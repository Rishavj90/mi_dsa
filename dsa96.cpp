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

Node* addEle_at_KthPlace(Node*head, int val, int k){
    Node* temp = new Node(val);
    if(k == 1){
        head->prev= temp;
        temp->next = head;
        return temp;
    }

    Node* i = head;
    Node* front;
    Node* back;
    int count = 0;
    while(i != NULL){
        count++;
        if(count == k){
            front = i;
            back = i->prev;
            break;
        }
        i = i->next;
    }
    temp->next = back->next;
    temp->prev= front->prev;
    back->next = temp;
    front->prev = temp;
    return head;
}

int main(){
    vector<int> vec = {0,3,4,6,7,8};
    Node* head = vector_toDLL(vec);
    head = addEle_at_KthPlace(head, 21,5);
    Node* i = head;
    while(i != NULL){
        cout << i->data << " ";
        i = i->next;
    }
    return 0;
}