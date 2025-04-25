#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node* vector_toLL(vector<int>& vec){
    Node* head = new Node(vec[0]);
    Node*mover = head;
    for(int i = 1; i < vec.size(); i++){
        Node* temp = new Node(vec[i]);
        mover->next= temp;
        mover = mover->next;  
    }
    return head;
}

int recursive_addOne(Node* head){
    if(head == nullptr) return 1;
    head->data = head->data + recursive_addOne(head->next);
    if(head->data != 10){
        return 0;
    }else{
        head->data = 0;
        return 1;
    }
}
Node* addOne(Node* head) {
    if(recursive_addOne(head) == 1){
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head;
}


int main(){
    vector<int> vec = {9,9,9};
    Node* head = vector_toLL(vec);
    head = addOne(head);
    Node* j = head;
    while(j != nullptr){
        cout << j->data;
        j = j->next;
    }
    return 0;
}