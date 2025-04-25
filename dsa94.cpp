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
int main(){
    vector<int> vec = {0,3,4,6,7,8};
    Node* head = vector_toDLL(vec);
    Node* i = head;
    while(i->next != NULL){
        cout << i->data << " ";
        i = i->next;
    }
    cout << endl;
    while(i != NULL){
        cout << i->data << " ";
        i = i->prev;
    }
    return 0;
}