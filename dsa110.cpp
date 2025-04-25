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

Node* reverseLL(Node* head){
    Node *prev = nullptr, *i = head, *front;
    while(i != nullptr){
        front = i->next;
        i->next = prev;
        prev = i;
        i = front;
    }
    return prev;
}
Node* addOne(Node* head) {
    Node* newHead = reverseLL(head);
    Node* j = newHead;
    while( j->data == 9 && j->next != nullptr){
        j->data = 0;
        j = j->next;
    }
    if(j->data == 9){
        j->data = 0;
        Node* tmp = new Node(1);
        j->next = tmp;
    }else{
        int num = j->data + 1;
        j->data = num;
    }
    return reverseLL(newHead);
}
int main(){
    vector<int> vec = {2,4,7,6,5,4,5,3,8,9,9,9};
    Node* head = vector_toLL(vec);
    head = addOne(head);
    Node* j = head;
    while(j != nullptr){
        cout << j->data;
        j = j->next;
    }
    return 0;
}