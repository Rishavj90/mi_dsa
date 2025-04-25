#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node* vector_toDLL(vector<int>& vec){
    Node* head = new Node(vec[0]);
    Node*mover = head;
    for(int i = 1; i < vec.size(); i++){
        Node* temp = new Node(vec[i]);
        mover->next= temp;
        mover = mover->next;  
    }
    return head;
}

Node* segregate(Node* head) {
    Node* zero = new Node(-1), *one = new Node(-1), *two = new Node(-1);
    Node* i = zero, *j = one, *k = two;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0){
            i->next = temp;
            i = i->next;
        }else if(temp->data == 1){
            j->next = temp;
            j = j->next;
        }else{
            k->next = temp;
            k = k->next;
        }
        temp = temp->next;
    }
    if(one->next != nullptr) i->next = one->next;
    else i->next = two->next;
    j->next = two->next;
    k->next = nullptr;
    Node* newHead = zero->next;
    delete zero;
    delete one;
    delete two;
    return newHead;
}
int main(){
    vector<int> vec = {2,1, 1, 2};
    Node* head = vector_toDLL(vec);
    head = segregate(head);
    Node* i = head;
    while(i != NULL){
        cout << i->data<< " ";
        i = i->next;
    }
    return 0;
}