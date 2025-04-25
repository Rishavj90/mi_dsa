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

Node* removeKthEle(Node* head, int k){
    //missing 4 edge cases
    Node* i = head;
    int count = 0;
    Node* front;
    Node* back;
    while(i != NULL){
        count++;
        if(count == k){
            front = i->next;
            back = i->prev;
            break;
        }
        i = i->next;
    }
    i->next->prev = back;
    i->prev->next = front;
    delete i;
    return head;
}

int main(){
    vector<int> vec = {0,3,4,6,7,8};
    Node* head = vector_toDLL(vec);
    head = removeKthEle(head, 3);
    Node* i = head;
    while(i != NULL){
        cout << i->data << " ";
        i = i->next;
    }
    return 0;
}