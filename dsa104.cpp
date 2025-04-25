#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
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

int countNodesinLoop(Node *head) {
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            int count = 0;
            fast = fast->next;
            while(fast != slow){
                count++;
                fast = fast->next;
            }
            return count;
        }
    }
    return 0;
}