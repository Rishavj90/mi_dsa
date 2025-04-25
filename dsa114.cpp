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

/* work for unsorted input as well
Node* removeDuplicates(struct Node *head){
    if(head == nullptr) return head;
    unordered_map<int, int> mpp;
    Node* i = head;
    while(i != nullptr){
        mpp[i->data]++;
        if(mpp[i->data] > 1){
            Node* back = i->prev, *front = i->next;
            back->next = front;
            if(front != nullptr)front->prev = back;
            Node* del_node = i;
            delete del_node;
            mpp[i->data]--;
            i = front;
        }else{
            i = i->next;
        }
    }
    mpp.clear();
    return head;
}
*/

Node* removeDuplicates(struct Node *head){
    if(head == nullptr) return head;
    Node* i = head->next;
    while(i != nullptr){
        if(i->data == i->prev->data){
            Node* back = i->prev, *front = i->next;
            back->next = front;
            if(front != nullptr)front->prev = back;
            Node* del_node = i;
            delete del_node;
            i = front;
        }else{
            i = i->next;
        }
    }
    return head;
}

int main(){
    vector<int> vec = {1,1};
    Node* head = vector_toDLL(vec);
    head = removeDuplicates(head);
    Node* i = head;
    while(i != nullptr){
        cout << i->data << " ";
        i = i->next;
    }
    return 0;
}