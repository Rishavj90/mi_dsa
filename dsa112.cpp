#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x) { data = x; next = prev = NULL; }
};
Node* vector_toDLL(vector<int>& vec){
    if(vec.size() == 0) return nullptr;
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

void deleteAllOccurOfX(struct Node** head_ref, int x) {
    if(*head_ref == nullptr) return;
    Node* i = *head_ref;
    Node* back = nullptr, *front = i->next; 
    while(i != nullptr){
        if(i->data == x){
            if(back != nullptr) back->next = front;
            if(front != nullptr) front->prev = back;
            if(i == *head_ref) *head_ref = front;
            Node* del_node = i;
            delete del_node;
            i = front;
            if(front != nullptr)front = front->next;
        }else{
            back = i;
            i = i->next;
            if(front != nullptr) front = front->next;
        }
    }
}
int main(){
    vector<int> vec = {9,1,9};
    Node* head = vector_toDLL(vec);
    deleteAllOccurOfX(&head, 9);
    Node* i = head;
    while(i != nullptr){
        cout << i->data;
        i = i->next;
    }
    return 0;
}