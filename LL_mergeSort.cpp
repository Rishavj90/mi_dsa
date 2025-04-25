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

Node* merge_LL(Node* left_head, Node* right_head){
    Node* sorted_LL = new Node(0);
    Node* i = sorted_LL;
    Node* l = left_head, *r = right_head;
    if(l->data <= r->data){
        i->data = l->data;
        l = l->next;
    }else{
        i->data = r->data;
        r = r->next;
    }
    while(l != nullptr && r != nullptr){
        if(l->data <= r->data){
            i->next = l;
            l = l->next;
            i = i->next;
        }else{
            i->next = r;
            r = r->next;
            i = i->next;
        }
    }
    if(l == nullptr){
        i->next = r;
    }else{
        i->next = l;
    }
    return sorted_LL;
}

Node* divide_LL(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    //splitting
    Node* fast = head, *slow = head;
    fast = fast->next->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }Node* left_head = head, *right_head = slow->next;
    slow->next = nullptr;
    left_head = divide_LL(left_head);
    right_head = divide_LL(right_head);
    return merge_LL(left_head, right_head);
}

Node* segregate(Node* head) {
    return divide_LL(head);
}

int main(){
    vector<int> vec = {1,2,2,1,2,0,2,2};
    Node* head = vector_toDLL(vec);
    head = segregate(head);
    Node* i = head;
    while(i != NULL){
        cout << i->data<< " ";
        i = i->next;
    }
    return 0;
}