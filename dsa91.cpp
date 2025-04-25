#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int a){
        data = a;
        next = nullptr;
    };
};

Node *insertAtEnd(Node *head, int x) {
    Node* temp = new Node(x);
    if(head == nullptr) return temp;
    Node* i = head;
    while(i->next != nullptr){
        i = i->next;
    }
    i->next = temp;
    return head;
}

int main(){
    
}